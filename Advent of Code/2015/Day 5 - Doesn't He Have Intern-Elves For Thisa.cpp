#include <bits/stdc++.h>
using namespace std;

bool checkIfNice(const string& input){
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
    unsigned vowel_count = 0;
    bool repeated = false;
    char last = '\0';

    for (char ch: input){
        if (vowels.find(ch) != vowels.end()){
            ++vowel_count;
        }
        if (ch == last){
            repeated = true;
        }
        if ((last == 'a' && ch == 'b') || (last == 'c' && ch == 'd') ||
            (last == 'p' && ch == 'q') || (last == 'x' && ch == 'y')){
            return false;
        }
        last = ch;
    }
    return repeated && vowel_count >= 3;
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



