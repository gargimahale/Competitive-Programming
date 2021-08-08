#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    int count_e = 0;
    for (char ch : s) {
        count_e += (ch == 'e');
    }

    count_e *= 2;
    cout << "h" + string(count_e, 'e') + "y\n";
}

int main(void) {
    solve();
}