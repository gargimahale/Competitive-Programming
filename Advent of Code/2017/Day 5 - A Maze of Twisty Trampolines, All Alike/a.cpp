#include <bits/stdc++.h>
using namespace std;

int getSteps( const vector<int> & input, function<void(int&)> update_fn ){
    vector<int> v = input;
    size_t index = 0;
    int count = 0;

    while (index < v.size()){
        auto & value = v[index];
        index = static_cast< size_t> ( static_cast<int> (index) + value );
        update_fn( value );
        ++count;
    }
    return count;
}

int main(void){
    vector<int> v;
    string line;
    ifstream myFile("input.txt");

    while(getline(myFile, line )){
        v.push_back(stoi(line));
    }

    cout << "Part 1: " << getSteps(v, []( int & value ) { ++value; }) << "\n";
    cout << "Part 2: " << getSteps(v, []( int & value ) { if(value >= 3) --value; else ++value; }) << "\n";
}