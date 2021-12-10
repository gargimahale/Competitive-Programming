#include <bits/stdc++.h>
using namespace std;

int main(void){
    string line;
    using ivec = vector<int>;
    ivec v;
    ifstream myFile("input.txt");
    map<ivec, int> seen;

    while(getline(myFile, line )){
        stringstream line_ss{ line };
        string token;

        while(getline(line_ss, token, '\t')){
            int i;
            stringstream token_ss{ token };
            token_ss >> i;
            v.push_back(i);
        }
    }

    int count = 0;
    bool inserted;

    do{
        auto max = max_element(v.cbegin(), v.cend());
        int value = *max;
        auto index = static_cast<size_t>(max - v.cbegin());
        v[index] = 0;

        while (value > 0){
            index = ++index % v.size();
            ++(v[index]);
            --value;
        }

        ++count;

        auto insert = seen.emplace(v, count);
        inserted = insert.second;
    }
    while (inserted);

    cout << "Part 1: " << count << "\n";
    int cycle_length = count - seen[v];
    cout << "Part 2: " << cycle_length << "\n";
}