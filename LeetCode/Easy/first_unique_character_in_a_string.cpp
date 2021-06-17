#include <bits/stdc++.h>

using namespace std;

int firstUniqueCharacterInAString(string s) {
    int array[26] = {0};
    for (int it = 0; it < s.length(); ++it) {
        array[s[it] - 'a']++;
    }
    for (int it = 0; it < s.length(); ++it) {
        if (array[s[it] - 'a'] == 1) {
            return it;
        }
    }
    return -1;
}

int main() {
    string str = "leetcode";
    cout << firstUniqueCharacterInAString(str) << endl;
    return 0;
}