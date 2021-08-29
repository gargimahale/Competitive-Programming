#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
    
    string encodeState(int& pos){
        vector<int> temp = sessions;
        sort(begin(temp), end(temp));
        
        string key = to_string(pos) + '$';
        for (int i = 0; i<temp.size(); ++i){
            key += to_string(temp[i]) + "$";
        }
        return key;
    }
    
    int dfs(vector<int>& tasks, int& sessionTime, int& n, int pos){
        if (pos >= n){
            return 0;
        }
        
        string key = encodeState(pos);
        
        if (dp.find(key) != dp.end()){
            return dp[key];
        }
        
        sessions.push_back(tasks[pos]);
        
        int ans = 1 + dfs(tasks, sessionTime, n, pos+1);
        sessions.pop_back();
        
        for (int i = 0; i < sessions.size(); ++i){
            if(sessions[i] + tasks[pos] <= sessionTime){
                sessions[i] += tasks[pos];
                ans = min(ans, dfs(tasks, sessionTime, n, pos+1));
                sessions[i] -= tasks[pos];
            }
        }
        return dp[key] = ans; 
    }
public:
    unordered_map<string , int> dp;
    vector<int> sessions;
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        return dfs(tasks, sessionTime, n, 0);
    }
};

