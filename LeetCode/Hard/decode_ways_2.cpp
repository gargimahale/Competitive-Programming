#include <bits/stdc++.h>
using namespace std;

bool isValid(char& a) {
	return a != '0';
}

bool isValid(char& a, char& b) {
	return (a == '1' || (a == '2' && b <= '6'));
}

int numDecodings(string s) {
	int n = s.size();
	if (n == 0 || s[0] == '0') {
		return 0;
	}
	if (n == 1) {
		return 1;
	}

	int f1 = 1, f2 = 1, cnt = 0, temp;
	for (int i = 1; i < n; ++i) {
		temp = f1;
		if (isValid(s[i]) && isValid(s[i - 1], s[i])) {
			cnt += f1 + f2;
		}
		if (!isValid(s[i]) && isValid(s[i - 1], s[i])) {
			cnt += f2;
		}
		if (isValid(s[i]) && !isValid(s[i - 1], s[i])) {
			cnt += f1;
		}
		if (!isValid(s[i]) && !isValid(s[i - 1], s[i])) {
			return 0;
		}
		f1 = cnt;
		f2 = temp;
		cnt = 0;
	}

	return f1;
}

int main(void) {
	cout << numDecodings("1234") << "\n";
}
