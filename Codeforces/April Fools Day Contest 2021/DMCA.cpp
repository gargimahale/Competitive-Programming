#include <bits/stdc++.h>
using namespace std;

// Digital Root

int main(){
    int n;
    cin >> n;
    while(n >= 10){
        int digit = 0;
        while(n > 0){
            digit += (n%10);
            n /= 10; 
        }
        n = digit;
    }
    cout << n << "\n";
}