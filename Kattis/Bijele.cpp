#include <bits/stdc++.h>
using namespace std;

void checkRoyal(const int& piece) {
    cout << to_string(1 - piece) << " ";
}

void checkHelpers(const int& piece) {
    cout << to_string(2 - piece) << " ";
}

void checkPawns(const int& piece) {
    cout << to_string(8 - piece) << "\n";
}

void solve() {
    int k, q, r, b, kni, p;
    cin >> k >> q >> r >> b >> kni >> p;
    checkRoyal(k);
    checkRoyal(q);
    checkHelpers(r);
    checkHelpers(b);
    checkHelpers(kni);
    checkPawns(p);
}

int main(void) {
    solve();
}