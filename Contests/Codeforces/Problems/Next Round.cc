#include <vector>
#include <iostream>
using namespace std;

void solve(){
	int n, k, i, j, a[51];
	cin >> n >> k;
	while(n > i)
		cin >> a[i++];
	while(a[j]&&a[j]>=a[k-1])
		++j;
	cout << j;
}	

int32_t main(){
	solve();
}
