#include<bits/stdc++.h>

using namespace std;

string solve(string num, int k) {
    if(k==num.size()) return "0";
    int i=0;
    while(k>0){
        i = (i>0) ? (i-1) : 0;
        while(i<num.size()-1 && num[i]<=num[i+1]) i++;
        num.erase(num.begin()+i), k--;
    }
    return num;
}

int main() {
    int t = 1, k;
    string num;
    cin >> num >> k;
    while(t--) cout << solve(num, k);
    return 0;
}