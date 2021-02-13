#include <bits/stdc++.h>

using namespace std;

int main(void){
    string inp;
    cin >> inp;
    int c=0, ans=1;
    char l = 'A';
    for(char d: inp){
        if (d == l){
            ++c;
            ans = max(ans, c);
        }
        else{
            l = d;
            c = 1;
        }
    }
    cout << ans << "\n";
}