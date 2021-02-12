#include <bits/stdc++.h>

using namespace std;

int solve(int num){
    int c=0, temp=num;
    while (temp!=0){
        temp=temp/2;
        c++;
    }
    cout << c << "\n";
    cout << (pow(2, c)-1-num);
    return 0;
}

int main(){
    int n;
    cin >> n;
    if (n>=1)
        solve(n);
    return 0;
}