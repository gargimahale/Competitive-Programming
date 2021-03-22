#include <bits/stdc++.h>

using namespace std;

#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define SRAN srand(chrono::high_resolution_clock::now().time_since_epoch().count());
#define gc getchar_unlocked
#define int long long
#define endl "\n"
#define PI 3.1415926535897932384626
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y, z) cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for(auto it = a.begin(); it != a.end(); it++)
const int mod = 1e9 + 7;


int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
	// deb(orders.size());
	priority_queue<pair<int, int>> buy;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sell;
	for (auto x : orders) {
		int price = x[0];
		int amt = x[1];
		int type = x[2];
		deb2(price, amt, type);
		if (type == 0) {
			if (sell.empty()) {
				buy.push({price, amt});
			}
			else {
				while (!sell.empty()) {
					auto x = sell.top();
					if (x.first <= amt) {
						sell.pop();
					}
					else {
						buy.push({price, amt});
						break;
					}
				}
			}
		}
		else {
			if (buy.empty()) {
				sell.push({price, amt});
			}
			else {
				while (!buy.empty()) {
					auto x = buy.top();
					if (x.first >= amt) {
						buy.pop();
					}
					else {
						sell.push({price, amt});
						break;
					}
				}
			}
		}
	}
	int ordersRemain = 0;
	deb(buy.size());
	deb(sell.size());
	while (!buy.empty()) {
		auto x = buy.top();
		deb(x.second);
		ordersRemain += x.second;
		buy.pop();
	}
	while (!sell.empty()) {
		auto y = sell.top();
		deb(y.second);
		ordersRemain += y.second;
		sell.pop();
	}
	deb(ordersRemain);
	return ordersRemain % mod;
}

int32_t main() {
	IOS
	SRAN
	// init_code();
	// int t = ;
	// cin >> t;
	vector<vector<int>> orders = {{7, 1000000000, 1}, {15, 3, 0}, {5, 999999995, 0}, {5, 1, 1}};
	cout << getNumberOfBacklogOrders(orders) << endl;
	return 0;
}