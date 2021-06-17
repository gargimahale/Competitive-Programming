#include <bits/stdc++.h>
using namespace std;

class TwoSum {
public:
    unordered_map<int, int> mp;
    /** Initialize your data structure here. */
    TwoSum() {}

    /** Add the number to an internal data structure.. */
    void add(int number) {
        mp[number]++;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        if (value >= INT_MAX || value <= INT_MIN) return false;

        for (auto it = mp.begin(); it != mp.end(); ++it) {
            int x = it->first;
            int y = value - x;
            if ((x == y && it->second > 1) || (x != y && mp.find(y) != mp.end())) {
                return true;
            }
        }

        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */