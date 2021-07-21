#include <bits/stdc++.h>
#define pb push_back

using namespace std;

void swapCase(string& str, int l) {
    if (islower(str[l])) {
        str[l] = toupper(str[l]);
    }
    else {
        str[l] = tolower(str[l]);
    }
}

void helperPermutation(string S, vector<string>& result, int start, int end) {
    if (start == end) {
        return;
    }
    for (int i = start; i <= end; ++i) {
        if (isalpha(S[i])) {
            swapCase(S, i);
            result.pb(S);
            helperPermutation(S, result, i + 1, end);
            swapCase(S, i);
        }
    }
}

vector<string> letterCasePermutation(string S) {
    vector<string> result;
    result.pb(S);
    helperPermutation(S, result, 0, S.size());
    return result;
}

int main() {
    string S = "a1b2";
    vector<string> res = letterCasePermutation(S);
    for (string i : res) {
        cout << i << " ";
    }
    return 0;
}
