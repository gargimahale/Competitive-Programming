#include <climits>
#include <vector>
using namespace std;

class Solution {
public:

	// Time: O(N), Space: O(1)
    bool increasingTriplet(vector<int>& nums) {
        int c1 = INT_MAX, c2 = INT_MAX;
        
        for(int& x: nums){
            if (x <= c1){
                c1 = x;
            }
            
            else if (x <= c2){
                c2 = x;
            }
            else{
                return true;
            }
        }
        
        return false;
    }
};