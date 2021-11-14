#include <bits/stdc++.h>
using namespace std;

long getMass(int& x){
	long res = 0;
	while(x > 0){
		x /= 3;
		x -= 2;
		if (x >= 0) res += x;
	}
	return res;
}

int main(void){
	ifstream file("input.txt");
	long long res = 0;
	int x;
	while(file >> x){
		res += getMass(x);
	}
	cout << res << "\n";
}