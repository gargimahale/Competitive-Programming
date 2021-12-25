#include <bits/stdc++.h>
using namespace std;

class FindPeak {
public:

    // TC: O(log N), SC: O(1)
    void findPeak_1D(const vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1]) {
                left = mid + 1;
            }
            else if (nums[mid] < nums[mid - 1]) {
                right = mid - 1;
            }
            else {
                cout << nums[mid] << "\n";
                break;
            }
        }
    }

    // Greedy Assent Algorithm
    void findPeak_2D(const vector<vector<int>>& nums) {
        int startCol = 0, endCol = mat[0].size() - 1;

        while (startCol <= endCol) {
            int maxRow = 0, midCol = startCol + (endCol - startCol) / 2;
            for (int row = 0; row < mat.size(); ++row) {
                maxRow = mat[row][midCol] >= mat[maxRow][midCol] ? row : maxRow;
            }

            bool isLeftBig = midCol - 1 >= startCol && mat[maxRow][midCol - 1] > mat[maxRow][midCol];
            bool isRightBig = midCol + 1 <= endCol && mat[maxRow][midCol + 1] > mat[maxRow][midCol];

            if (!isLeftBig && !isRightBig) {

                // peak is found
                return vector<int> {maxRow, midCol};
            }
            else if (isRightBig) {
                startCol = midCol + 1;
            }
            else {
                endCol = midCol - 1;
            }
        }
        return vector<int> { -1, -1};
    }
};

int main(void) {
    FindPeak fp;
    fp.findPeak_1D({1, 2, 3, 5, 3, 2, 1});
    fp.findPeak_2D({{}, {}, {}});
}