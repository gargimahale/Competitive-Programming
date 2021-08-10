#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> arr(m+n);

    // Input
    for(int i=0; i<n; ++i) cin >> a[i];
    for(int i=0; i<m; ++i) cin >> b[i];

    int i=0, j=0, k=0;
    while(i < a.size() || j < b.size()){
        if (j == b.size() || (i < a.size() && a[i] < b[j])){
            arr[k++] = a[i++];
        }
        else{
            arr[k++] = b[j++];
        }
    }
    for (int x: arr){
        cout << x << " ";
    }
    return 0;
}