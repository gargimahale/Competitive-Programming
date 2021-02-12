#include <bits/stdc++.h>

using namespace std;

// Using BFS
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        bool ans = false;
        queue<int> idx;
        idx.push(start);
        // setting is at negative to mark as visited
        arr[start] *= -1;
        while(!idx.empty()){
            int pos = idx.front();
            idx.pop();
            // Future
            int forwardPos = pos+abs(arr[pos]);
            if (forwardPos < arr.size() && arr[forwardPos] >= 0){
                if (arr[forwardPos] == 0){
                    return true;
                }
                arr[forwardPos] *= -1;
                idx.push(forwardPos);
            }
            // Past
            int backwardPos = pos-abs(arr[pos]);
            if (backwardPos >= 0 && arr[backwardPos] >= 0){
                if (arr[backwardPos] == 0){
                    return true;
                }
                arr[backwardPos] *= -1;
                idx.push(backwardPos);
            }
        }
        return ans;
    }
};


// OR - Recursively ------------------------------------ DFS
class Solution {
public:
    
    bool helperCanReach(vector<int>& arr, int start, vector<bool>& visited){
        if (start < 0 || start >= arr.size() || visited[start]){
            return false;
        }
        if (arr[start] == 0){
            return true;
        }
        visited[start] = true;
        return helperCanReach(arr, start+arr[start], visited) || helperCanReach(arr, start-arr[start], visited);
    }
    
    bool canReach(vector<int>& arr, int start) {
        vector<bool>visited(arr.size(), false);
        return helperCanReach(arr, start, visited);
    }
};

// Or Using unordered_Set

class Solution {
public:
    unordered_set<int> vis; 
    
    bool canReach(vector<int>& arr, int start) {
        if (start >= 0 && start < arr.size() && vis.insert(start).second){
            return arr[start] == 0 || canReach(arr, start+arr[start]) || canReach(arr, start-arr[start]);
        }
        return false;
    }
};