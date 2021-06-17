#include <bits/stdc++.h>

using namespace std;

bool solve(string ransomNote, string magazine) {
    int c = 0;
    for (int i = 0; i < ransomNote.length(); i++) {
        for (int j = 0; j < magazine.length(); j++) {
            if (ransomNote[i] == magazine[j]) {
                c++;
                magazine[j] = ' ';
                break;
            }
        }
    }
    if (c == ransomNote.length()) {
        return true;
    }
    return false;
}

int main() {
    string r, m;
    cin >> r >> m;
    cout << solve(r, m);
    return 0;
}