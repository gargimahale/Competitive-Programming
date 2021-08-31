#include <algorithm>
#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <string>
using namespace std;


void solve(){
	string str;
	cin >> str;
	int len = str.length();
	string temp;
	if (len > 10){
		cout << str[0] + to_string(len-2) + str[len-1] << "\n";
		return;
	}
	cout << str << "\n";
}

int32_t main(){
	int T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}