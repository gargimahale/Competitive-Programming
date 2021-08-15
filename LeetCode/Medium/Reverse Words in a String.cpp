#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)

class Solution {
public:
    void reverseStr(string& s, int start, int end) {
        while (start < end) {
            swap(s[start++], s[end--]);
        }
    }

    void reverseWords(string& s, int& n) {
        int i = 0, j = 0;
        while (j < n) {
            while (i < j || (i < n && s[i] == ' ')) ++i;
            while (j < i || (j < n && s[j] != ' ')) ++j;
            reverseStr(s, i, j - 1);
        }
    }

    string formattedStr(string&s, int& n) {
        int i = 0, j = 0;
        while (j < n) {
            while (j < n && s[j] == ' ') ++j;
            while (j < n && s[j] != ' ') s[i++] = s[j++];
            while (j < n && s[j] == ' ') ++j;
            if (j < n) s[i++] = ' ';
        }
        return s.substr(0, i);
    }

    string reverseWords(string s) {
        int n = s.length();
        if (n == 0) return " ";

        reverseStr(s, 0, n - 1); // O(N)
        reverseWords(s, n); // O(N)
        return formattedStr(s, n); // O(N)
    }
};

int32_t main(){
    Solution S;
    cout << S.reverseWords("A man, a lake, a ball look what that is!!!");
    return 0;
}