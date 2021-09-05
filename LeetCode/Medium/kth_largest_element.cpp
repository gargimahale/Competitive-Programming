#include <vector>
#include <queue>
using namespace std;



class Solution {
public:

    // O(NLogN)
    int findKthLargest(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        return nums[nums.size() - k];
    }

    // O(NlogK)
    int findKthLargest_1(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &x : nums) {
            pq.push(x);
            if (pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }


    // Avg Case: O(N), Worst Case cause of pivot selection is O(N^2)
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        swap(nums[left], nums[right]);
        int new_pivot = left;
        for (int i = left; i < right; ++i) {
            if (nums[i] > pivot) {
                swap(nums[i], nums[new_pivot++]);
            }
        }
        swap(nums[right], nums[new_pivot]);
        return new_pivot;
    }

    int findKthLargest_2(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1, kth;
        while (left <= right) {
            int new_pivot = partition(nums, left, right);

            if (new_pivot == k - 1) {
                kth = nums[new_pivot];
                break;
            }
            else if (new_pivot < k - 1) {
                left = new_pivot + 1;
            }
            else {
                right = new_pivot - 1;
            }
        }
        return kth;
    }

    int findKthLargest_3(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.begin()+k-1, nums.end(), greater<int>());
        return nums[k-1];
    }

};