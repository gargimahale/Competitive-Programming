#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int size = rolls.size();
        int sum = 0;
        for (int i = 0; i < size; ++i) sum += rolls[i];
        
        int x = ((mean + n) * mean) - sum;
        int low = 1 * n, high = 6 * n;
        if (x < low || x > high){
            return {};
        }
        
        cout << x << " " << low << " " << high << " ";
        
        int find_closest = 1;
        for (int i = 1; i <= 6; ++i){
            if (x/i == n){
            	if (i > find_closest)
                	find_closest = i;
            }
        }
        
        cout << find_closest << "\n";
        return {};
    }
};

int main(void){
	Solution sol;
	vector<int> rolls = {1};
	int mean = 3, n = 1;
	vector<int> arr = sol.missingRolls(rolls, mean, n);

	for (int x: arr) cout << x << " ";
}