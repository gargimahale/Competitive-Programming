#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
// #include <>
using namespace std;

long fact(int n){
	long f = 1;
	for (int i = 1; i<=n; ++i){
		f *= (long)i;
	}
	return f;
}

void nextPerm(string& s){
	int k = s.size()-2;

	while(k >= 0 && s[k] >= s[k+1]) --k;

	if (k < 0){
		reverse(begin(s), end(s));
	}
	else{
		int i = 0;
		for (int i = s.size()-1; i > k; --i){
			if (s[i] > s[k]){
				break;
			}
		}
		swap(s[i], s[k]);
		reverse(begin(s)+k+1, end(s));
	}
}

bool doesNotMatchPos(string& orig, string& newSt){
	int i = 0;
	while(i < orig.size()){
		if (orig[i] == newSt[i]){
			return false;
		}
		++i;
	}
	return true;
}

void solve(int test_case){
	string S;
	cin >> S;

	// cout << "Case #" << test_case << ": "; 
	long comb = fact((int)S.length());
	cout << comb << "\n";
	unordered_set<string> U;
	U.insert(S);
	string dup = S;
	sort(begin(dup), end(dup));
	for (int i = 0; i<comb; ++i){
		nextPerm(dup);
		if (!U.count(dup) && doesNotMatchPos(S, dup)){
			// cout << dup << "\n";
			return;
		}
	}
	// cout << "IMPOSSIBLE\n";
}

int32_t main(){
	int T;
	cin >> T;
	for (int i = 1; i<=T; ++i){
		solve(i);
	}
	return 0;
}