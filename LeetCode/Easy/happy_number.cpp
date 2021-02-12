#include<bits/stdc++.h>

using namespace std;

int f(int n){
    int sum=0;
    while(n){
        int digit = n%10;
        n/=10;
        sum+=(digit*digit);
    }
    return sum;
}

bool solve(int n) {
    unordered_set<int> visited;
    while(true){
        if (n==1) return true;
        n = f(n);
        if(visited.count(n)==1) return false;
        visited.insert(n);
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1,n;
    cin >> n;
    while(t--) {
      	cout << solve(n) << "\n";
    }
    return 0;
}