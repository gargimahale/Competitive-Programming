#include <bits/stdc++.h>
#define pb push_back

using namespace std;

void getString(string S, string newString, vector<string>& result, int i) {
    if (i == S.size()) {
        result.pb(newString);
        return;
    }
    if (S[i] == '{') {
        vector<char> current;
        while (S[i] != '}') {
            if (isalpha(S[i])) {
                current.pb(S[i]);
            }
            i++;
        }
        for (char ch : current) {
            getString(S, newString + ch, result, i + 1);
        }
    }
    else if (isalpha(S[i])) {
        getString(S, newString + S[i], result, i + 1);
    }
}

vector<string> expand(string S) {
    vector<string> result;
    getString(S, "", result, 0);

    // Returns Lexigraphically
    sort(result.begin(), result.end());
    return result;
}

int main() {
    string s = "{a,b}c{d,e}f";
    vector<string> res = expand(s);
    for (string r : res) {
        cout << r << " ";
    }
    cout << "\n";
    return 0;
}