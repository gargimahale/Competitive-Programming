#include <bits/stdc++.h>
using namespace std;

/*

So, we pivot this problem into Two Sum Closest: generate all possible sums for the first half of the array and
store it in a set h1. Then, generate possible sums for the second half in h2.

For each sum from the second half, use binary search to find a complement sum in the first half.
Additional optimizations:
    Compute sum of all positive and all negative values. If the goal is larger (or smaller),
    we know what's the best at this point.
    Check if res == 0 and exit. We cannot do better than zero!
    Check if a sum is already in the set and do not search for a compliment in this case.

*/

class Solution {
public:
    int minAbsDifference(vector<int>& ns, int goal) {
        int res = abs(goal), pos = 0, neg = 0;
        for (int x : ns) {
            pos += max(0, x);
            neg += min(0, x);
        }

        if (goal < neg || goal > pos) {
            return min(abs(neg - goal), abs(goal - pos));
        }

        set<int> h1{0}, h2{0};

        for (auto i = 0; i < ns.size() / 2; ++i) {
            for (auto n : vector<int> (begin(h1), end(h1))) {
                if (h1.insert(n + ns[i]).second) {
                    res = min (res, abs(goal - n - ns[i]));
                }
            }
        }


        for (auto i = ns.size() / 2; i < ns.size(); ++i) {
            for (auto n : vector<int> (begin(h2), end(h2))) {
                if (h2.insert(n + ns[i]).second) {
                    auto it = h1.lower_bound(goal - n - ns[i]);
                    if (it != end(h1)) {
                        res = min(res, abs(goal - n - ns[i] - *it));
                    }
                    if (it != begin(h1)) {
                        res = min(res, abs(goal - n - ns[i] - *prev(it)));
                    }

                    if (res == 0) {
                        return res;
                    }
                }
            }
        }
        return res;
    }
};
