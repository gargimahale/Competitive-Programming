#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main(void){
    long n;
    cin >> n;
    int mx = 0;
    ll ans = 0;
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        mx = max(mx, x);
        ans += mx-x;
    }
    cout << ans << "\n";
}