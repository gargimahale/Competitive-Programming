#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> arr (126);
        for (char ch: t) arr[ch]++;
        
        // counter: #chars of t to be found in s
        int start = 0, end = 0, counter = t.size(), minStart = 0, minLen = INT_MAX;
        int n = s.size();
        
        // Move end to find a valid window.
        while(end < n){
            // If char in s exists in t, decrease counter
            if (arr[s[end]] > 0){
                --counter;
            }
            
            // Decrease m[s[end]]. If char does not exist in t, m[s[end]] will be negative.
            arr[s[end]]--;
            ++end;
            
            // When we found a valid window, move start to find smaller window.
            while(counter == 0){
                if (end-start < minLen){
                    minStart = start;
                    minLen = end-start;
                }
                
                // When char exists in t, increase counter.
                if (++arr[s[start]] > 0){
                    ++counter;
                }
                ++start;
            }
        }
        
        if (minLen != INT_MAX){
            return s.substr(minStart, minLen);
        }
        return "";
    }
};