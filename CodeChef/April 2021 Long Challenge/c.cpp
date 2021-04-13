#include <bits/stdc++.h>
using namespace std;


void solve(){
    long long n, k, cnt = 0, maxCnt = 0;
    cin >> n >> k;
    string s;
    cin >> s;

    for (char ch: s){
        if (ch == '*'){
            ++cnt;
            maxCnt = max(maxCnt, cnt);
            if (maxCnt >= k){
                cout << "YES\n";
                return;
            }
        }
        else
            cnt = 0;
    }
    cout << "NO\n";
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}