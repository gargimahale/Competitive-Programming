#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    for (int i=2; i < (int)s.size(); ++i){
        int first = (int) (s[i - 2] - 'A');
        int second = (int) (s[i - 1] - 'A');
        int third = (int) (s[i - 0] - 'A');
        
        if ((first + second) % 26 != third){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
