#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0);
#define endl "\n"
// #define int long long
const int N = 1e5 + 5;


string tictactoe(vector<vector<int> >& moves) {
	int n = moves.size();
	int rowSum[3] = {0};
	int colSum[3] = {0};
	int diagSum = 0;
	int reverseDiagSum = 0;

	for (int i = 0; i < n; ++i) {
		int row = moves[i][0];
		int col = moves[i][1];
		int player = i % 2 == 0 ? 1 : -1;

		rowSum[row] += player;
		colSum[col] += player;

		if (col == row) diagSum += player;
		if (row + col == 2) reverseDiagSum += player;

		if (abs(rowSum[row]) == 3 || abs(colSum[col]) == 3 ||
		        abs(diagSum) == 3 || abs(reverseDiagSum) == 3) {
			if (player == 1) {
				return "A";
			}
			if (player == 2) {
				return "B";
			}
		}
	}
	if (n < 9) return "Pending";
	return "Draw";
}

int32_t main() {
// #ifndef ONLINE_JUDGE
	// freopen ("inp.txt", "r", stdin);
	// freopen ("out.txt", "w", stdout);
// #endif
	vector<vector<int> > moves = {{0, 0}, {2, 0}, {1, 1}, {2, 1}, {2, 2}};
	// cin >> moves;
	cout << tictactoe(moves) << endl;
	return 0;
}