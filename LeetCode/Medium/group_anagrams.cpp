#include <bits/stdc++.h>

// TC: O(NK Log K) SC: O(N) - Using normal sort
// where N is the length of strs
// K is the length of the longest string in strs
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    unordered_map<string, vector<string>> m;
    for (string &s : strs) {
        string t = s;
        sort(t.begin(), t.end());
        m[t].push_back(s);
    }

    for (auto& e : m) {
        res.push_back(e.second);
    }
    return res;
}

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(strs);
    for (auto x : res) {
        for (auto a : x) {
            cout << a << " ";
        }
        cout << "\n";
    }
}

// Using Counting Sort
// TC: O(NK), SC: O(NK)
// where N is the length of strs
// K is the length of the longest string in strs
class Solution {
public:

    string countingSort(string t) {
        int cnt[26] = {0};
        for (char ch : t) cnt[ch - 'a']++;
        string ans;
        for (int i = 0; i < 26; ++i) {
            ans += string(cnt[i], i + 'a');
        }
        return ans;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (string x : strs) {
            string temp = x;
            mp[countingSort(temp)].push_back(x);
        }

        for (auto x : mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};