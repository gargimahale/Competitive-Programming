#include <bits/stdc++.h>
using namespace std;

class Solution {
    void findCombinations(vector<int> comb, int k, int n, int j) {
        if (n == 0 && comb.size() == k) {
            ans.push_back(comb);
            return;
        }

        for (int i = j; i <= 9; ++i) {
            if (n - i < 0) {
                break;
            }
            comb.push_back(i);
            findCombinations(comb, k, n - i, i + 1);
            comb.pop_back();
        }
    }
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        findCombinations({}, k, n, 1);
        return ans;
    }
};
