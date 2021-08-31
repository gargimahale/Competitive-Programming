#include <cstdint>
#include <vector>
#include <iostream>
using namespace std;

void solve(){
	int N, K;
	cin >> N >> K;
	int total_time = 240;
	if (K >= total_time){
		cout << "0";
		return;
	}

	int sum = 0, count = 0;
	for (int i = 1; i<=N; ++i){
		sum += 5 * i;
		if (sum + K <= total_time){
			++count;
		}
		else{
			break;
		}
	}
	cout << count << "\n";
}

int32_t main(void){
	solve();
}