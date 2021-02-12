#include <bits/stdc++.h>

using namespace std;

class FirstUnique {
public:
    unordered_map<int, int> mp;
    queue<int> q;

    FirstUnique(vector<int>& nums) {
        for (int x: nums){
            mp[x]++;
            q.push(x);
        }
    }

    int showFirstUnique() {
        while(!q.empty()){
            if (mp[q.front()] == 1){
                return q.front();
            }
            q.pop();
        }
        return -1;
    }

    void add(int value) {
        mp[value]++;
        q.push(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
