#include<bits/stdc++.h>

using namespace std;

bool canPermutePalindrome(string s) {
    unordered_map<char, int> map;
    for (char ch: s){
        map[ch]++;
    }
    int check = 0;
    for(auto it = map.begin(); it!=map.end(); ++it){
        if(it->second%2 == 1){
            ++check;
        }
    } 
    return check < 2;
}

int main(){
    string s = "aab";
    cout << canPermutePalindrome(s) << "\n";
}