#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

template<class T> struct seg_tree {
	const T ID = 0;
	T combine(T a, T b) {
		return __gcd(a, b);
	}

	int n;
	vector<T> seg;
	void init(int _n) {
		n = _n;
		seg.assign(4 * n, ID);
	}

	void pull(int u) {
		seg[u] = combine(seg[2 * u], seg[2 * u + 1]);
	}

	void build(vector<T>& a, int u, int l, int r) {
		if (l == r) {
			seg[u] = a[l];
			return;
		}
		int mid = (l + r) / 2;
		build(a, 2 * u, l, mid);
		build(a, 2 * u + 1, mid + 1, r);
		pull(u);
	}

	void build(vector<T>& a) {
		build(a, 1, 0, n - 1);
	}

	void upd(int x, T val, int u, int l, int r) {
		if (l > x || r < x) return;
		if (l == r) {
			seg[u] = val;
			return;
		}
		int mid = (l + r) / 2;
		upd(x, val, 2 * u, l, mid);
		upd(x, val, 2 * u + 1, mid + 1, r);
		pull(u);
	}

	void upd(int x, T val) {
		upd(x, val, 1, 0, n - 1);
	}

	T qry(int x, int y, int u, int l, int r) {
		if (l > y || r < x) return ID;
		if (x <= l && r <= y) return seg[u];
		int mid = (l + r) / 2;
		return combine(qry(x, y, 2 * u, l, mid), qry(x, y, 2 * u + 1, mid + 1, r));
	}

	T qry(int x, int y) {
		return qry(x, y, 1, 0, n - 1);
	}
};

struct HLD {
	int n, r;
	vector<int> val;
	vector<int> new_val;
	vector<int> par;
	vector<int> sz;
	vector<int> dep;
	vector<int> heavy;
	vector<int> head;
	vector<int> pos; //hld stuff
	vector<vector<int>> adj;
	seg_tree<ll> tree;

	void add(int a, int b) {
		adj[a].push_back(b); adj[b].push_back(a);
	}
	HLD(int _n) : n(_n) {
		val.assign(n, 0);
		par.resize(n);
		sz.assign(n, 1);
		dep.resize(n);
		heavy.assign(n, -1);
		head.resize(n);
		pos.resize(n);
		adj.resize(n);
	}

	void init(int _r = 0) {
		r = _r;
		dep[r] = 0;
		posInd = 0;
		par[r] = -1;
		dfs_info(r);
		dfs_hld(r, r);
		tree.init(n);
	}
	void init(vector<int> v) {
		assert(v.size() == n);
		val = v;
	}

	void dfs_info(int u) {
		for (int v : adj[u]) {
			adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
			par[v] = u;
			dep[v] = dep[u] + 1;
			dfs_info(v);
			sz[u] += sz[v];
			if (heavy[u] == -1 || sz[v] > sz[heavy[u]]) {
				heavy[u] = v;
			}
		}
	}

	int posInd;
	void dfs_hld(int u, int top) { //top is top of chain (head)
		pos[u] = posInd++;
		new_val.push_back(val[u]);
		head[u] = top;
		if (heavy[u] != -1) {
			dfs_hld(heavy[u], top);
		}
		for (int v : adj[u]) {
			if (v != heavy[u]) {
				dfs_hld(v, v);
			}
		}
	}

	int lca(int u, int v) {
		for (; head[u] != head[v]; v = par[head[v]]) {
			if (dep[head[u]] > dep[head[v]]) {
				swap(u, v);
			}
		}
		return dep[u] < dep[v] ? u : v;
	}

	ll combine(ll a, ll b) {return __gcd(a, b);}
	ll qryHelp(int u, int v) { //u is higher
		ll x = 0;
		while (head[u] != head[v]) {
			x = combine(x, tree.qry(pos[head[v]], pos[v]));
			v = par[head[v]];
		}
		x = combine(x, tree.qry(pos[u] + 1, pos[v]));
		return x;
	}
	ll qry(int u, int v) {
		int a = lca(u, v);
		ll x = qryHelp(a, u);
		ll y = qryHelp(a, v);
		ll res = combine(x, y);
		//res=combine(res, tree.qry(pos[a], pos[a]));
		return res;
	}

	void upd(int u, int v, ll x) { //u is higher
		if (pos[v] > pos[u])
			swap(u, v);
		tree.upd(pos[u], x);
	}
};

const int mxN = 100000;
int n, q;
ll ans[mxN];
vector<ar<ll, 4>> e;
ar<int, 3> qry[mxN];

void test_case() {
	e.clear();
	cin >> n >> q;
	HLD t(n);
	for (int i = 1; i < n; ++i) {
		int u, v, w;
		ll a;
		cin >> u >> v >> w >> a, --u, --v;
		e.push_back({w, u, v, a});
		t.add(u, v);
	}
	for (int i = 0; i < q; ++i)
		cin >> qry[i][1] >> qry[i][0], --qry[i][1], qry[i][2] = i;
	sort(qry, qry + q);
	sort(e.rbegin(), e.rend());
	t.init();
	for (int i = 0; i < q; ++i) {
		//cerr << i << " ";
		while (!e.empty() && e.back()[0] <= qry[i][0]) {
			t.upd(e.back()[1], e.back()[2], e.back()[3]);
			e.pop_back();
		}
		ans[qry[i][2]] = t.qry(0, qry[i][1]);
	}
	for (int i = 0; i < q; ++i)
		cout << ans[i] << " ";
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int _ = 1; _ <= t; ++_) {
		cout << "Case #" << _ << ": ";
		test_case();
	}
	return 0;
}

