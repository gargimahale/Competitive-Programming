#include <bits/stdc++.h>

using namespace std;

int main(){
    int V = 5;
    // Vertices are 0(A), 1(B), 2(C), 3(D), 4(E)
    vector<vector<int>> adj(V);
    adj[0].push_back(1);
    adj[0].push_back(3);
    adj[1].push_back(2);
    adj[3].push_back(2);
    adj[3].push_back(4);

    // Print Neighbors of D
    for(int v: adj[3]) cout << v << " ";
    cout << "\n";
    return 0;
}