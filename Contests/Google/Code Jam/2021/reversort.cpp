#include<bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0); 

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];

    int ans = 0;
    for(int i=0; i<n-1; ++i){
        int minIdx = j;
        for (int j = i+1; j<n; ++j){
            if (a[j] < a[minIdx]){
                minIdx = j;
            }
            ++j;
        }
        reverse(a.begin()+i, a.begin()+minIdx+1);
        ans += (minIdx - i + 1);
    }
    return ans;
}

int main() {
    IOS
    int t, tc = 0;
    cin >> t;
    while(t--) {
        tc++;
        int ans = solve();
        cout << "Case #" << tc << ": " << ans << "\n";
    }
    return 0;
}