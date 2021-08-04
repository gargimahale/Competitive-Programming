#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& pos, vector<int>& speed) {
        map<int, double> mp;
        for (int i = 0; i < pos.size(); ++i) {
            mp[-pos[i]] = (double)(target - pos[i]) / speed[i];
        }

        double curr = 0;
        int res = 0;

        for (auto x : mp) {
            if (x.second > curr) {
                ++res;
                curr = x.second;
            }
        }
        return res;
    }
};

// TC: O(nlogn)
// SC: O(N)

// OR
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {

        int n = position.size(), m = speed.size();

        if (!n || !m || !target) return 0;
        vector<pair<int, double>> log;

        for (int i = 0; i < n; ++i) {
            double time = (double)(target - position[i]) / speed[i];
            log.push_back({position[i], time});
        }

        sort(begin(log), end(log));

        int fleets = 0;
        double curr = 0;

        for (int i = n - 1; i >= 0; --i) {
            if (log[i].second > curr) {
                curr = log[i].second;
                ++fleets;
            }
        }

        return fleets;
    }
};

// TC: O(NlogN), SC: O(N)