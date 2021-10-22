#include <vector>
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
            combination.push_back(candidates[i]);
            
            // the helper function will be called with the same element idx as the number taken can be repeated
            countCombinations(candidates, target - candidates[i], combination, i);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(begin(candidates), end(candidates));
        countCombinations(candidates, target, {}, 0);
        return res;
    }
};