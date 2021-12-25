#include <bits/stdc++.h>
using namespace std;

void solve(int& T){
	long long N, D, C, M, i;
	cin >> N >> D >> C >> M;
	string S;
	cin >> S;
	bool check = false;

	for (i = 0; i < S.size(); ++i){
		if (S[i] == 'D' && D > 0){
			--D;
			C += M;
		}
		else if (S[i] == 'C' && C > 0){
			--C;
		}
		else{
			break;
		}
	}

	for (int j = i; j < S.size(); ++j){
		if (S[j] == 'D'){
			check = true;
			break;
		}
	}
	if (!check){
		cout << "Case #" << T << ": YES\n"; 
	}
	else{
		cout << "Case #" << T << ": NO\n";
	}
}

int main(){
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i){
		solve(i);
	}
	return 0;
}