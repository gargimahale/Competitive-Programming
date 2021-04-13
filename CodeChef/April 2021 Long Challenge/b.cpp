#include <bits/stdc++.h>
using namespace std;

void solve(){
    double k1, k2, k3, v;
    cin >> k1 >> k2 >> k3 >> v;

    double total = 100 / (k1 * k2 * k3 * v);

    total = round(total * 100.0) / 100.0;

    if (total < 9.58){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int main(){
    int T;
    cin >> T;
    while (T--){
        solve();
    }
    return 0;
}