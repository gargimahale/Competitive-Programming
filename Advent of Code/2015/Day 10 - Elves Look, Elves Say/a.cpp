#include <bits/stdc++.h>
using namespace std;

string lookAndSay(const string& res){
    string temp;
    int n = res.size();
    for (int i = 0; i < n; ++i) {
        int count = 1;
        while (i + 1 < n && res[i] == res[i + 1]) {
            ++i, ++count;
        }
        temp += to_string(count) + res[i];
    }
    return temp;
}

int main(void){
	string inp = "1113122113";
	for (int i = 0; i < 40; ++i){
		inp = lookAndSay(inp);
	}
	cout << "Part 1: " << (int)inp.size() << "\n";


	inp = "1113122113";
	for (int i = 0; i < 50; ++i){
		inp = lookAndSay(inp);
	}
	cout << "Part 2: " << (int)inp.size() << "\n";
}
    
