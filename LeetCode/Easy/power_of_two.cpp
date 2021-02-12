#include <bits/stdc++.h>

using namespace std;

bool isPowerofTwo(int n){
    int cnt=0, temp=n;
    while(temp>1) temp/=2, cnt++;
    if(pow(2, cnt) == n) return true;
    return false;
}

int main(){
    int n;
    cin >> n;
    cout << isPowerofTwo(n);
    return 0;
}