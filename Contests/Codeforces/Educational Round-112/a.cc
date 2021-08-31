#include <bits/stdc++.h>
using namespace std;

long long solve(){
	long long n;
	cin >> n;
	return max(6LL, n + 1) / 2 * 5;
}

int32_t main(){
	int t;
	cin >> t;
	while(t--){
		cout << solve() << '\n';
	}
	return 0;
}
