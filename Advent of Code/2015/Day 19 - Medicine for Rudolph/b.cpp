#include <bits/stdc++.h>
using namespace std;

template <typename Map>
size_t dedup(Map const &replacements, string &molecule) {
    size_t steps = 0;
    for (auto const &kv : replacements) {
        if (kv.first != kv.second + kv.second) {
            continue;
        }
        size_t pos = string::npos;
        do {
            pos = molecule.find(kv.first);
            if (pos != string::npos) {
                molecule = molecule.substr(0, pos) + kv.second +
                molecule.substr(pos + kv.first.size());
                ++steps;
            }
        } while (pos != string::npos);
    }

    return steps;
}

template <typename Map>
bool is_good_replacement(Map const &replacements, string const &nm,
                         size_t pos, size_t replace_len) {
    for (auto const &kv : replacements) {
        auto left = max(kv.first.size(), pos) - kv.first.size();
            if (nm.substr(left, kv.first.size() * 2 + replace_len).find(kv.first) !=
            string::npos) {
            return true;
        }
    }
    return false;
}

template <typename Map>
size_t find_molecule(Map &replacements, string const &molecule) {
    random_device rd;
    mt19937 g(rd());
    while (true) {
        string m = molecule;
        bool changed = true;
        shuffle(replacements.begin(), replacements.end(), g);
        size_t steps = 0;
        do {
            changed = false;
            for (auto const &kv : replacements) {
                auto pos = m.find(kv.first);
                if (pos != string::npos) {
                    m = m.substr(0, pos) + kv.second + m.substr(pos + kv.first.length());
                    ++steps;
                    changed = true;
                    if (m == "e") {
                        return steps;
                    }
                }
            }
        } while (changed);
    }
}

int main(void) {
    vector<pair<string, string>> replacements;
    bool collecting_replacements = true;
    string line;
    ifstream myFile("input.txt");
    while (getline(myFile, line)) {
        if (line.empty()) {
            collecting_replacements = false;
        } 
        else if (collecting_replacements) {
            auto sep = line.find(" => ");
            replacements.push_back({line.substr(sep + 4), line.substr(0, sep)});
        } 
        else {
            auto time = find_molecule(replacements, line);
            cout << "Part 2: " << time << "\n";
        }
    }
}