#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    // Input
    for(int i=0, inp; i<n; ++i) {
        cin >> inp;
        a[inp]++;
    }
    int cnt = 0;
    for(int i=0, inp; i<m; ++i) {
        cin >> inp;
        if (a[inp] > 0) cnt += a[inp];
    }
    cout << cnt;
    return 0;
}