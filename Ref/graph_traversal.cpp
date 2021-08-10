#include<bits/stdc++.h>
using namespace std;

class Graph{
    int m_v;
    vector<vector<int>> m_adj;
    void dfs_rec(int s, vector<bool>& visited){
        visited[s]=true;
        cout << s << " ";
        for (int u: m_adj[s]){
            if(!visited[u]) dfs_rec(u, visited);
        }
    }

    public:
        Graph(int v): m_v(v), m_adj(v){
        }
    void addEdge(int u, int v){
        m_adj[u].push_back(v);
        // m_adj[v].push_back(u); // undirected
    }
    // ---------- Applications of BFS:---------
    // 1. Shortest Path in undirected graph
    // 2. Cycle Detection
    // 3. Path between 2 nodes
    // 4. MST in unweighted graph
    // 5. Bipartite Check
    // 6. Social n/w websites
    // 7. GPS Navigation
    // 8. Network Broadcasting
    // 9. Connected Components
    void BFS(int s){
        queue<int> Q;
        vector<bool> visited(m_v, false);
        Q.push(s);
        visited[s]=true;
        while(!Q.empty()){
            int v = Q.front();
            Q.pop();
            cout << v << " ";
            for (int u: m_adj[v]){
                if(!visited[u]){
                    Q.push(u);
                    visited[u]=true;
                }
            }
        }
    }
    // ---------- Applications of DFS:---------
    // 1. Find Minimum Spanning Tree
    // 2. Cycle Detection
    // 3. Path between 2 nodes
    // 4. Topological Sorting (DAG)
    // 5. Bipartite Check
    // 6. SCC
    // 7. Maze Problem
    void DFS(){
        vector<bool> visited(m_v, false);
        for (int i=0;i<m_v;++i){
            if(!visited[i]) dfs_rec(i, visited);
        }
    }
};

int main(){
    Graph G(5);
    G.addEdge(0,1);
    G.addEdge(0,3);
    G.addEdge(1,2);
    G.addEdge(3,2);
    G.addEdge(3,4);
    G.DFS();
    return 0;
}