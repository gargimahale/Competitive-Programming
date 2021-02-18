#include <bits/stdc++.h>

using namespace std;

int main(){
    string str;
    cin >> str;
    string res;
    for(int i=0; i<str.size(); ++i){
        if (isupper(str[i])){
            res += str[i];
        }
    }
    cout << res; 
    return 0;
}