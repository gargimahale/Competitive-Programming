#include <vector>
using namespace std;

// This is the BinaryMatrix's API interface.
// You should not implement it, or speculate about its implementation
class BinaryMatrix {
public:
	int get(int row, int col);
	vector<int> dimensions();
};

class Solution {
public:

	// Linear Search
	// Time: O(N+M), Space: O(1)
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int rows = binaryMatrix.dimensions()[0], col = binaryMatrix.dimensions()[1];
        if (!rows){
            return -1;
        }
        
        int check = col-1;
        for (int i = 0; i<rows; ++i){
            while(check >= 0 && binaryMatrix.get(i, check) == 1){
                --check;
            }
        }
        
        return (check == col-1) ? -1: check+1;
    }

    // Binary Search
    // Time: O(NlogM), Space: O(1)
    bool existsInCol(BinaryMatrix &binaryMatrix, int rows, int cols){
        for (int r = 0; r < rows; ++r){
            if (binaryMatrix.get(r, cols) == 1){
                return true;
            }
        }
        return false;
    }

    int leftMostColumnWithOne_bs(BinaryMatrix &binaryMatrix) {
        int rows = binaryMatrix.dimensions()[0], col = binaryMatrix.dimensions()[1];
        if (!rows){
            return -1;
        }
        
        int left = 0, right = col-1, ans = -1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if (existsInCol(binaryMatrix, rows, mid)){
                ans = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};