#include <bits/stdc++.h>
using namespace std;

void generate_molecules(string medicine, const pair<string,string>& replacement, set<string>& molecules) {
    int p = -1;
    string newmedicine;
    while ((p = medicine.find(replacement.first,p+1)) != string::npos) {
        // cout << "p: " << p << endl;
        int s = replacement.first.size();
        newmedicine = medicine;
        newmedicine.replace(p, s, replacement.second);
        molecules.insert(newmedicine);
    }
}

int main(void) {
    string line;
    vector<pair<string, string>> replacements;
    string medicine;

    int replace_line = 1;
    ifstream myFile("input.txt");
    while (getline(myFile, line)) {
        if (line.length() == 0) 
            replace_line = 0;
        else {
            if (replace_line == 1) {
                size_t p = line.find(" => ");
                replacements.push_back(make_pair(line.substr(0, p), line.substr(p+4)));
            } else {
                medicine = line;
            }
        }
    }

    set<string> molecules;
    for (auto repl: replacements) {
        // cout << "Working on " << repl.first << " to " << repl.second << endl;
        generate_molecules(medicine, repl, molecules);
    }

    cout << "Part 1: " << molecules.size() << endl;
}