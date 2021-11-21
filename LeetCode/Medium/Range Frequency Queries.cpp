#include <bits/stdc++.h>
using namespace std;

class RangeFreqQuery {
public:
    vector<int> ids[10001] = {};
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); ++i){
            ids[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        return upper_bound(begin(ids[value]), end(ids[value]), right) - 
            lower_bound(begin(ids[value]), end(ids[value]), left);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */