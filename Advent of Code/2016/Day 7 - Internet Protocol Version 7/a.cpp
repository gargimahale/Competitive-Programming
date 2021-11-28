#include <bits/stdc++.h>
using namespace std;

vector<string> getFileLines(const string &filename, const char delim = '\n') {
    vector<string> result;
    ifstream f(filename);
    string line;

    while (getline(f, line, delim)) {
        result.push_back(line);
    }
    f.close();
    return result;
}

bool isAbba(const string in) {
    if (in[0] != in[1]) {
        if (in[0] == in[3] && in[1] == in[2]) {
            return true;
        }
    }

    return false;
}

bool isAba(const string in) { 
    return in[0] != in[1] && in[0] == in[2]; 
}

bool supportsTLS(const string line) {
    string word;
    bool inbrackets{false};
    bool inside{false};
    bool outside{false};
    for (auto c : line) {

        if (c == '[') {
            inbrackets = true;
            word = "";
        } else if (c == ']') {
            inbrackets = false;
            word = "";
        } else {

            word += c;

            if (word.size() > 4) {
                word.erase(0, 1);
            }

            if (word.size() == 4) {
                if (isAbba(word)) {

                    if (inbrackets) {
                        inside = true;
                    } else {
                        outside = true;
                    }
                }
            }
        }
    }
    return outside && !inside;
}

bool supportsSSL(const string line) {
    string word;
    bool inbrackets{false};

    vector<string> inAbas;
    vector<string> outAbas;

    for (auto c : line) {

        if (c == '[') {
            inbrackets = true;
            word = "";
        } else if (c == ']') {
            inbrackets = false;
            word = "";
        } else {

            word += c;

            if (word.size() > 3) {
                word.erase(0, 1);
            }

            if (word.size() == 3) {
                if (isAba(word)) {

                    if (inbrackets) {
                        inAbas.push_back(word);
                    } else {
                        outAbas.push_back(word);
                    }
                }
            }
        }
    }

    for (auto inAba : inAbas) {
        for (auto outAba : outAbas) {
            if(inAba[0] == outAba[1]){
                if(inAba[1] == outAba[0]){
                    return true;
                }
            }
        }
    }

    return false;
}

void process(const string filename) {
    auto lines = getFileLines(filename);

    int count{0};
    int count2{0};
    for (auto line : lines) {
        if (supportsTLS(line)) {
            count++;
        }
        if (supportsSSL(line)) {

            count2++;
        }
    }

    cout << "part1: " << count << "\n";
    cout << "part2: " << count2 << "\n";
}

int main(void) {
    process("input.txt");
}