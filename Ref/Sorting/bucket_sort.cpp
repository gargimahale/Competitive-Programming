#include<bits/stdc++.h>
using namespace std;

void bucketSort(vector<float>& arr, int n){
    // Create n empty buckets
    vector<float> b[n];
    // Put array elements in different buckets
    for (int i=0; i<n; i++) {
    int bi = n*arr[i]; // Index in bucket
    b[bi].push_back(arr[i]);
    }
    // Sort individual buckets
    for (int i=0; i<n; i++) sort(b[i].begin(), b[i].end());
    // Concatenate all buckets into arr
    int idx = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
        arr[idx++] = b[i][j];
}

int main() {
    vector<float> arr = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    bucketSort(arr, arr.size());
    for (float n: arr) cout << n << " ";
    cout << endl;
    return 0;
}
