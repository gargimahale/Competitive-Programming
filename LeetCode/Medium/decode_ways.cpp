#include <bits/stdc++.h>

using namespace std;

bool isValid(char a) {
    return a != '0';
}

bool isValid(char a, char b) {
    return a == '1' || (a == '2' && b <= '6');
}

int solve(string s) {
    int n = s.size();
    if (n == 0 || s[0] == '0') return 0;
    if (n == 1) return 1;
    int f1 = 1, f2 = 1, count = 0;
    for (int i = 1; i < n; ++i) {
        int temp = f1;
        if (isValid(s[i]) && isValid(s[i - 1], s[i])) count += f1 + f2;
        if (!isValid(s[i]) && isValid(s[i - 1], s[i])) count += f2;
        if (isValid(s[i]) && !isValid(s[i - 1], s[i])) count += f1;
        if (!isValid(s[i]) && !isValid(s[i - 1], s[i])) return 0;
        f1 = count;
        f2 = temp;
        count = 0;
    }
    return f1;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
    string s = "1234";
    cout << s << "\n";
    cout << solve(s);
    return 0;
}
