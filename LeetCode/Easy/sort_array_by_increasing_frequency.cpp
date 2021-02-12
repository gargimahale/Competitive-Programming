#include <bits/stdc++.h>
#define pb push_back
#define pi pair<int, int>

using namespace std;


// OR
// class Solution {
// public:
//     vector<int> frequencySort(vector<int>& nums) {
//         vector<pair<int, int>> map;
//         unordered_map<int, int> U;
//         for (int num: nums){
//             U[num]++;
//         }
//         for (auto x: U){
//             map.push_back({x.second, x.first});
//         }
//         sort(begin(map), end(map), [&](pair<int, int>a, pair<int, int>b){
//             return a.first == b.first ? a.second > b.second : a.first < b.first;
//         });
//         vector<int> ans;
//         for (auto ele: map){
                // (it, count, element to be repeated) 
//             ans.insert(ans.end(), ele.first, ele.second);
//         }
//         return ans;
//     }
// };


vector<int> frequencySort(vector<int>& nums) {
//     unordered_map<int, int> M;
//     M.clear();
//     for (int x: nums) {
//         M[x]++;
//     }
//     vector<pi> result;
//     vector<int> answer;
//     for (int x: nums) {
//         result.push_back({M[x], x});
//     }
//     sort(result.begin(), result.end(), [&](pi a, pi b) {
//         if (a.first == b.first){
//             return a.second > b.second;
//         }
//         return a.first < b.first;
//     });

//     for (pi x: result){
//         answer.push_back(x.second);
//     }
//     return answer;


    // OR

    int cnt[201] = {};
    for (auto n : nums){
        ++cnt[n + 100];
    }
    sort(begin(nums), end(nums), [&](int a, int b) {
        return cnt[a + 100] == cnt[b + 100] ? a > b : cnt[a + 100] < cnt[b + 100];
    });
    return nums;
}

int main(){
    vector<int> nums = {1, 1, 2, 2, 2, 3};
    nums = frequencySort(nums);
    for (int x: nums){
        cout << x << " ";
    }
    return 0;
}
