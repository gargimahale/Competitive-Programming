#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_set<int> s;
        unordered_map<int, int>map;
        for (int x : arr) {
            ++map[x];
        }
        for (auto x : map) {
            if (s.count(x.second) > 0) {
                return false;
            }
            s.insert(x.second);
        }
        return true;
    }
};