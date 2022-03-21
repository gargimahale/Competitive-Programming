#include <bits/stdc++.h>
using namespace std;

int findSum(string S, int len){
	int sum = 0;
	for (int i = 0; i < len; ++i){
		sum += (S[i] - '0');
		sum %= 9;
	}
	if (sum) sum = 9-sum;
	return sum;
}

int main(){
	int T;
	cin >> T;

	for (int i = 0; i < T; ++i){
		string S;
		cin >> S;

		int len = S.size();
		int sum = findSum(S, len);
		int at = S.size();
		
		for (int k = sum == 0; k < len; ++k){
			if (S[k] - '0' > sum){
				at = k;
				break;
			}
		}

		cout << "Case #" << i+1 << ": ";
		for (int p = 0; p < at; ++p) putchar(S[p]);
		putchar('0' + sum);
		for (int p = at; p < len; ++p) putchar(S[p]);
		puts("");
	}
}