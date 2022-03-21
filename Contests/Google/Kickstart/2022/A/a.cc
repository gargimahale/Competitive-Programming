#include <bits/stdc++.h>
using namespace std;

int main(){
	long long T;
	cin >> T;

	for (int i = 0; i < T; ++i){
		string original, produced, result = "IMPOSSIBLE";
		cin >> original >> produced;

		int length = 0, changes = 0;

		long long s1 = 0, s2 = 0;
		while(s1 < (int)original.size() && s2 < (int)produced.size()){
			if (original[s1] == produced[s2]){
				++length;
				++s1; ++s2;
			}
			else{
				++s2;
				++changes;
			}
		}

		if (length == (int)original.size()){
			while (s2 < (int)produced.size()){
				++changes;
				++s2;
			}
			cout << "Case #" << i+1 << ": " << changes << "\n";
		}
		else{
			cout << "Case #" << i+1 << ": " << result << "\n";
		}
	}
}	