#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, j = 0;
    cin >> T;
    while (T--) {
        int n, i;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        string res = "A";

        for (i = 0; i < n; ++i) {
            if (i & 1) {
                if (a[i] > res.back() - 'A') {
                    res.pop_back();
                    res.push_back('A' + a[i]);
                }
                char ch = 'A' + a[i];
                while (a[i]--) {
                    ch--;
                    res += ch;
                }
            } else {
                char ch = 'B';
                while (a[i]--) {
                    res += ch;
                    ch++;
                }
            }
        }
        cout << "Case #" << ++j << ": " << res << "\n";
    }
    return 0;
}