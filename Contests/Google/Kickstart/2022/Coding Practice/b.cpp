#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long T;
    cin >> T;
    for (int i = 0; i < T; ++i){
        string input;
        cin >> input;
        char lastChar = tolower(input.back());
        
        if (lastChar == 'y'){
            cout << "Case #" << i+1 << ": " << input << " is ruled by nobody." << "\n";
        } 
        else if (lastChar == 'a' || lastChar == 'e' || lastChar == 'i'
        || lastChar == 'o' || lastChar == 'u'){
            cout << "Case #" << i+1 << ": " << input << " is ruled by Alice." << "\n";
        }
        else{
            cout << "Case #" << i+1 << ": " << input << " is ruled by Bob." << "\n";
        }
    }
}