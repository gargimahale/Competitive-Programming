//
// Created by Gargi Mahale on 2/6/21.
//

#include <bits/stdc++.h>

using namespace std;

int findIndex(vector<int>& a, int& val, bool flag){
    int l = -1, r = a.size();
    while (r > l+1){
        int mid = l+(r-l)/2;
        if (flag){
            if (val > a[mid]){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        else{
            if (a[mid] <= val){
                l = mid;
            }
            else{
                r = mid;
            }
        }
    }
    return !flag ? l+1 : r+1;
}

int main(){
    int n, k;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i) cin >> a[i];
    sort(begin(a), end(a));
    cin >> k;
    for (int i=0; i<k; ++i){
        int l, r;
        cin >> l >> r;
        // int left = lower_bound(begin(a), end(a), l) - a.begin();
        // int right = upper_bound(begin(a), end(a), r) - a.begin();

        // OR
        int left = findIndex(a, l, false);
        int right = findIndex(a, r, true);
//        cout << left << " " << right << "\n";
        cout << right-left+1 << " ";
    }
    return 0;
}

