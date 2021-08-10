//#include <bits/stdc++.h>

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    unordered_map<int, int> map;

    // Input
    int cnt = 0;
    for(int i=0; i<n; ++i) {
        cin >> a[i];
        map[a[i]]++;
    }
    for(int i=0; i<m; ++i) cin >> b[i];
    for (int x: b){
        cnt += map[x];
    }
    cout << cnt << "\n";
    return 0;
}