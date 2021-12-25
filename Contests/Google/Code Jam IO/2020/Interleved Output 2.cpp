#include <bits/stdc++.h>
using namespace std;

void solve() {
    string str;
    cin >> str;
    int cnt = 0;
    int i = 0, j = 0;
    string temp;
    while (j < str.size()) {
        while (j < str.size()) {
            if (str[i] == 'i' || str[i] == 'I') {
                temp += str[i++];
                break;
            }
        }
        while (j < str.size()) {
            if (str[j] == 'O' || str[j] == 'o') {
                temp += str[j++];
                break;
            }
        }

        if ("IO" == temp) {
            ++cnt;
        }
        temp = "";
    }
    cout << cnt << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T, i = 0;
    cin >> T;
    while (T--) {
        ++i;
        solve();
        cout << "Case #" << i << ": ";
    }
    return 0;
}