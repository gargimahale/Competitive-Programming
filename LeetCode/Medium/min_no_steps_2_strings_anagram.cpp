#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int arr[26]={0};
        int sum = 0;
        for (char a: s){
            arr[a-'a']++;
        }
        for (char b: t){
            arr[b-'a']--;
        }

        for (int x: arr){
            if (x<0){
                sum+=x;
            }
        }
        return abs(sum);
    }
};
