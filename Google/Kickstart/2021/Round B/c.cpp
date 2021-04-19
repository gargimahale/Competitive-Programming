#include <bits/stdc++.h>
using namespace std;

// Consecutive Primes

bool isPrime(long long n) {
	for (long long i = 2; i <= sqrt(n); ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void gogo(long long Z) {
	long long B = sqrt(Z) + 200;
	long long p = -1;

	while (B >= 0) {
		if (isPrime(B)) {
			if (p != -1 && (p * B) <= Z) {
				cout << p*B << "\n";
				return;
			}
			p = B;
		}
		--B;
	}
}

int main(void) {
	int T = 0, j = 0;
	long long Z = 0;
	cin >> T;
	while (T--) {
		cin >> Z;
		cout << "Case #" << ++j << ": ";
		gogo(Z);
	}
}