#include <bits/stdc++.h>
using namespace std;

int main(void){
    string line;
    map<string, int> registers;
    ifstream myFile("input.txt");

    int max_seen = numeric_limits<int>::lowest();

    while(getline(myFile, line)){
        istringstream line_ss{ line };
        string reg;
        string op;
        int value;
        string dummy;
        string cond_a;
        string cond;
        int cond_b;
        line_ss >> reg >> op >> value >> dummy >> cond_a >> cond >> cond_b;

        map<string, function<bool(int,int)>> cond_map;

    #define add_cond(_cond_) cond_map[#_cond_] = [](int a, int b) { return a _cond_ b; }

        add_cond(<);
        add_cond(>);
        add_cond(<=);
        add_cond(>=);
        add_cond(==);
        add_cond(!=);

        if (cond_map[cond](registers[cond_a], cond_b)){
            if (op == "inc") registers[reg] += value;
            else if (op == "dec") registers[reg] -= value;

            max_seen = max(max_seen, registers[reg]);
        }
    }

    auto max = max_element(registers.cbegin(), registers.cend(), [](auto & a, auto & b){ 
        return a.second < b.second; 
    });

    cout << "Part 1: " << max->first << " " << max->second << endl;
    cout << "Part 2: " << max_seen << endl;
}