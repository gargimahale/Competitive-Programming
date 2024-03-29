#include <bits/stdc++.h>
#include <fstream>
using namespace std;

vector<int> split(string s, string del=" ") {
    int start = 0;
    int end = s.find(del);
    vector<int> v;
    while (end != -1) {
        int n = atoi(s.substr(start, end-start).c_str());
        v.push_back(n);
        start = end + del.size();
        end = s.find(del, start);
    }
    v.push_back(atoi(s.substr(start, end-start).c_str()));
    return v;
}

void print_vector(vector<int> v) {
    for (auto& n: v) 
        cout << n << " ";
    cout << "\n";
}

void print_table(vector<vector<int>> table) {
    for (auto& v: table) 
        print_vector(v);
    cout << "\n";
}

void print_grid(vector<vector<vector<int>>> grid) {
    for (auto& t: grid)
        print_table(t);
    cout << "\n";
}

bool check_table1(vector<vector<int>> table) {
    bool flag = false;
    for (auto& line: table) {
        flag = true;
        for (auto& n: line) {
            if (n != -1)
                flag = false;
        }
        if (flag) return true;
    }
    return false;
}

bool check_table2(vector<vector<int>> table) {
    for (int i = 0; i < table[0].size(); i++) {
        bool flag = true;
        for (int j = 0; j < table.size(); j++) {
            if (table[j][i] != -1)
                flag = false;
        }
        if (flag) return true;
    }
    return false;
}

int sum_table(vector<vector<int>> table) {
    int sum = 0;
    for (auto& line: table) {
        for (auto& n: line) {
            if (n != -1)
                sum += n;
        }
    }
    return sum;
}

int main(void) {
    string line;
    ifstream infile("input.txt");
    getline(infile, line);

    vector<int> numbers = split(line, ",");

    getline(infile, line);
    vector<vector<vector<int>>> grids;
    vector<vector<int>> table;
    while (getline(infile, line)) {
        if (line.size() <= 1) {
            grids.push_back(table);
            table.clear();
            continue;
        }
        istringstream iss(line);
        int a,b,c,d,e;
        iss >> a >> b >> c >> d >> e;
        vector<int> v = {a, b, c, d, e};
        table.push_back(v);
        

    }
    grids.push_back(table);
    print_grid(grids);
    cout << grids.size() << " " << grids[0].size() << "\n";

    vector<vector<int>> best;
    bool flag = false;
    int last;
    for (auto& n: numbers) {
        if (flag) break;
        for (auto& table: grids) {
            for (auto& line: table) {
                for (int i = 0; i < line.size(); i++) {
                    if (line[i] == n)
                        line[i] = -1;
                }
            }
            if (check_table1(table) || check_table2(table)) {
                best = table;
                last = n;
                flag = true;
                break;
            }
        }
    }
    int sum = sum_table(best);
    cout << sum << " " << last << " " << sum * last << "\n";
}