#include <bits/stdc++.h>

using namespace std;


int main(){
    int t, n, cnt = 0;
    cin >> t;
    while(t--){
        cin >> n;
        if (n < 0){
            ++cnt;
        }
    }
    cout << cnt;
    return 0;
}