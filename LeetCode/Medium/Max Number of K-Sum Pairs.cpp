#include <bits/stdc++.h>

using namespace std;

int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    int ans = 0;
    for(int& x: nums){
        map[x]++;
    }
    
    for(auto it=map.begin(); it!=map.end(); ++it){
        int num = it->first, freq = it->second;
        if(k-num == num){
            ans += map[k-num]/2;
        }
        else if(map.count(k-num)){
            int min_fq = min(freq, map[k-num]);
            ans += min_fq;
            map[k-num] -= min_fq;
            map[num] -= min_fq;
        }
    }
    return ans;
}

int main(){
	vector<int> nums = {1, 2, 3, 4};
	int k = 5;
	cout << maxOperations(nums, k) << "\n";
}