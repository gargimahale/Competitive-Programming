#include <vector>
using namespace std;

class SparseVector {
public:
    vector<pair<int, int>> V;
    SparseVector(vector<int> &nums) {
        for (int i = 0; i<nums.size(); ++i){
            if (nums[i]){
                V.push_back({i, nums[i]});
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec, int res = 0) {
        for (int i = 0, j = 0; i<V.size() && j <vec.V.size(); ++i, ++j){
            if (V[i].first < vec.V[j].first) --j;
            else if (V[i].first > vec.V[j].first) --i;
            else{
                res += V[i].second * vec.V[j].second;
            }
        }
        return res;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
