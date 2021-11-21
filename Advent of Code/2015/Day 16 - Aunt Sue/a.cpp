#include <bits/stdc++.h>
using namespace std;

using Sue = map<string, int>;

void processFile(const char *filename) {
    ifstream f(filename);
    string line, str;
    vector<Sue> sues;

    while (getline(f, line)) {
        istringstream iss(line);
        Sue sue;
        string name;
        char c;
        int v;

        iss >> str >> str;
        while (!iss.eof()) {
            iss >> name >> v >> c;

            name.erase(name.end() - 1);
            sue[name] = v;
        }

        sues.push_back(sue);
    }

    f.close();

    map<string, int> input = {
        {"children", 3}, {"cats", 7},     {"samoyeds", 2}, {"pomeranians", 3},
        {"akitas", 0},   {"vizslas", 0},  {"goldfish", 5}, {"trees", 3},
        {"cars", 2},     {"perfumes", 1},
    };

    map<string, function<bool(const int a, const int b)>>
        comparators = {
            {"cats", [](auto a, auto b) { return a > b; }},
            {"trees", [](auto a, auto b) { return a > b; }},
            {"pomenarians", [](auto a, auto b) { return a < b; }},
            {"goldfish", [](auto a, auto b) { return a < b; }},
    };

    for (unsigned int i = 0; i < sues.size(); ++i) {
        auto &sue = sues[i];
        bool possible{true};

        for (auto &kv : input) {
            if (sue.find(kv.first) != sue.end()) {
                auto comparator = comparators.find(kv.first);
                if (comparator == comparators.end()) {
                    if (sue[kv.first] != kv.second) {
                        possible = false;
                        break;
                    }
                } 
                else {
                    if (!(comparator->second)(sue[kv.first], kv.second)) {
                        possible = false;
                        break;
                    }
                }
            }
        }

        if (possible) {
            cout << "Sue " << (i + 1) << endl;
        }
    }
}

int main(void) {
    processFile("input.txt");
}