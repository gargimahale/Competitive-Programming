#include <bits/stdc++.h>
using namespace std;

class Graph {
	int m_V;
	vector<vector<int>> m_adj;

public:
	Graph(int v): m_V(v), m_adj(v) {}

	void addEdge(int u, int v) {
		m_adj[u].push_back(v);
	}

	void bfs(int s) {
		queue<int> Q;
		vector<bool> visited(m_V, false);

		Q.push(s);
		visited[s] = true;

		while (!Q.empty()) {
			int x = Q.front(); Q.pop();
			cout << x << " ";

			for (int t : m_adj[x]) {
				if (!visited[t]) {
					Q.push(t);
					visited[t] = true;
				}
			}
		}
	}

};

int main() {
	Graph G(5);
	G.addEdge(0, 1);
	G.addEdge(0, 3);
	G.addEdge(1, 2);
	G.addEdge(3, 2);
	G.addEdge(3, 4);
	G.bfs(0);
	return 0;
}


