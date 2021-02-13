#include <bits/stdc++.h>

using namespace std;

int main(void){
    long n, sum = 0;
    cin >> n;
    for (int i=1; i<n; ++i){
        int a;
        cin >> a;
        sum += a;
    }
    cout << n*(n+1)/2 - sum << "\n";
}