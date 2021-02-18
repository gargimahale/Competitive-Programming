#include <bits/stdc++.h>

using namespace std;

int main(){
    int t, n, inp;
    cin >> t;
    while(t--){
        cin >> n;
        int cnt = 0;
        for (int i=0; i<n; ++i){
            cin >> inp;
            cnt += inp;
        }
        cout << cnt+1-n << "\n";
    }
    return 0;
}