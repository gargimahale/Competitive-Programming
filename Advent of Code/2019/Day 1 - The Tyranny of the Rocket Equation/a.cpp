#include <bits/stdc++.h>
using namespace std;

int getMass(int& x){
	int final_M = x/3;
	return final_M-2;
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