#include <bits/stdc++.h>

using namespace std;

int main(){
    ios:: sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];

    for (int i=0; i<k; ++i){
        int x;
        // bool found = false;
        cin >> x;
        // int l = 0, r = n-1;
        // while (l <= r){
        //     int mid = l+(r-l)/2;
        //     if (a[mid] == x){
        //         cout << "Element Found at index: " << mid << "\n";
        //         found = true;
        //         break;
        //     }
        //     else if (a[mid] > x){
        //         r = mid-1;
        //     }
        //     else{
        //         l = mid+1;
        //     }
        // }
        // if (!found) {
        //     cout << "Element not Found!\n";
        // }
        int l = -1, r = n;
        while(r > l+1){
            int m = l + (r-l)/2;
            if (a[m] < x) l = m;
            else r = m;
        }
        if (r < n && a[r] == x) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

