#include <vector>
#include <iostream>
using namespace std;

void solve(){
	int N, count = 0;
	cin >> N;
	vector<int> arr(N, 0);
	int a, b, c;
	for (int i = 0; i<N; ++i){
		cin >> a >> b >> c;
		arr[i] = a+b+c;
	}

	for (int i = 0; i<N; ++i){
		count += (arr[i] >= 2);
	}

	cout << count << "\n";
}

int32_t main(){
	solve();	
}