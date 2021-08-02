#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void countCombinations(vector<int>& candidates, int target, vector<int> combination, int start) {
        if (target == 0) {
            res.push_back(combination);
            return;
        }

        for (int i = start; i < candidates.size() && target >= candidates[i]; ++i) {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            combination.push_back(candidates[i]);
            countCombinations(candidates, target - candidates[i], combination, i + 1);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        countCombinations(candidates, target, {}, 0);
        return res;
    }
};
