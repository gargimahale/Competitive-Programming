#include <vector>
using namespace std;


// Time: O(N), Space: O(1)
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        int maxHeight = 0;
        vector<int> res;
        for (int i = n-1; i>=0; --i){
            if (res.empty() || heights[i] > maxHeight){
                res.push_back(i);
                maxHeight = heights[i];
            }
        }
        reverse(begin(res), end(res));
        return res;
    }
};