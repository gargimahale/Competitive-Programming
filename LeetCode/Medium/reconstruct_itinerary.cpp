#include <bits/stdc++.h>

using namespace std;

void dfs(unordered_map <string, multiset<string>>& adj, vector <string>& result, string s) {
    while (adj[s].size()) {
        string temp = *(adj[s].begin());
        adj[s].erase(adj[s].begin());
        dfs(adj, result, temp);
    }
    result.push_back(s);
}

vector<string> solve(vector<vector<string>>& tickets) {
    unordered_map <string, multiset<string>> adj;
    // Creates the adjacency list
    for (auto t : tickets) {
        adj[t[0]].insert(t[1]);
    }
    vector <string> result;
    dfs(adj, result, "JFK");
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<vector<string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    vector <string> sol = solve(tickets);
    for (string a : sol) cout << a << " ";
    cout << "\n";
    return 0;
}