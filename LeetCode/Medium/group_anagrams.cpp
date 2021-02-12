#include <bits/stdc++.h>

// Multiple valued hash map!

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

int main(){
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> res = groupAnagrams(strs);
    for (auto x: res){
        for (auto a: x){
            cout << a << " ";
        }
        cout << "\n";
    }
}