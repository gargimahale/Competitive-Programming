#include <bits/stdc++.h>
using namespace std;

bool checkIfNice(const string& input){
    bool repeated_pair = false;
    bool repeated_sep = false;

    for (int i = 0; i < input.size()-2; ++i){
        if (input.substr(i+2).find(input.substr(i, 2))){
            repeated_pair = true;
        }
        if (input[i] == input[i+2]){
            repeated_sep = true;
        }
    }
    return repeated_pair && repeated_sep;
}

int main(void){
    ifstream myFile("input.txt");
    string input;
    int res = 0;
    while(!myFile.eof()){
        myFile >> input;
        res += checkIfNice(input);
    }
    cout << res << "\n";
}