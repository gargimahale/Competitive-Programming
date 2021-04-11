#include <bits/stdc++.h>
using namespace std;


int main(){
    vector<int> A = {5, 5, 5};

    int m = 3, k = 1;
    if (A.size() < m)
        return -1;

    vector<int> temp;
    int p = m;
    for (int i = A.size() - 1; i >= 0; --i){
        temp.push_back(A[i]);
        --p;
        if (p == 0)
            break;
    }

    // Sort
    sort(begin(temp), end(temp));

    // find the smallest and the biggest

    int cnt = 0;
    int sum = 0;
    // int check = temp.size()-k;
    for (int i = k; i < temp.size() - k; ++i)
    {
        sum += temp[i];
        ++cnt;
    }
    // cout << sum << " " << cnt;
    cout << sum / cnt;
}