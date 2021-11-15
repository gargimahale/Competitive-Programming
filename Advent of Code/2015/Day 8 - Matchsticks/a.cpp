#include <bits/stdc++.h>
using namespace std;

int processEscape(const string& s){
	bool escape = false;
	int result = 0, skip = 0;

	for (auto c: s){
		if (skip > 0){
			--skip;
			continue;
		}

		if (escape){
			switch(c){
				case '\\': ++result; break;
				case '\"': ++result; break;
				case 'x': skip = 2; ++result; break;
			}
			escape = false;
		}
		else{
			if (c == '\\') escape = true;
			else ++result;
		}
	}
	return result-2;
}

int escape(const string& s){
	int result = 0;
	for (auto c: s){
		switch(c){
			case '\\': result += 2; break;
			case '\"': result += 2; break;
			default: ++result;
		}
	}
	return result+2;
}

int main(void){
	ifstream file("input.txt");
	string inp;
	int total_chars = 0, res = 0, res2 = 0;
	while(file >> inp){
		total_chars += inp.size();
		res += processEscape(inp);
		res2 += escape(inp);
	}
	cout << "Part 1: " << total_chars-res << "\n";
	cout << "Part 2: " << res2-total_chars << "\n";
}