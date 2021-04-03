#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    set<int> S;
    while(n){
        if (!S.insert(n%m).second){
            cout << "NO\n";
            return 0;
        }
        n /= m;
    }
    cout << "YES\n";
}