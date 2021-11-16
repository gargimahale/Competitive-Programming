#include <bits/stdc++.h>
using namespace std;

int do_parse(const string& s, int& pos){
	int result = 0;
	bool ignore = false;

	while(pos < (int)s.size()){
		if (s[pos] == '{'){
			++pos;
			result += do_parse(s, pos);
		}
		else if (s[pos] == '['){
			++pos;
			result += do_parse(s, pos);
		}
		else if (s[pos] == '}'){
			++pos;
			return ignore ? 0: result;
		}
		else if (s[pos] == ']'){
			++pos;
			return result;
		}
		else if (s[pos] == '"'){
			++pos;
			auto e = s.find('"', pos);
			assert(e != string::npos);
			string v = s.substr(pos, e-pos);
			if (v == "red"){
				ignore = true;
			}
			pos = e+1;
		}
		else if (isdigit(s[pos]) || s[pos] == '-'){
			size_t len = 0;
			result += stoi(s.substr(pos), &len);
			pos += len;
		}
		else{
			assert(s[pos] == ',' || s[pos] == ':');
			++pos;
		}
	}
	return result;
}

int parse_numbers(const string& s){
	int pos = 0;
	int result = do_parse(s, pos);
	assert(pos == s.size());
	return result;
}

int processLine(string& str){
	int i = 0, num = 0, res = 0;
	int sign = 1;
	while(i < (int)str.size()){
		while(i < (int)str.size() && !isdigit(str[i])) ++i;
		num = 0, sign = 1;
		if (i > 0 && str[i-1] == '-') sign = -1;
		while(i < (int)str.size() && isdigit(str[i])){
			num = num * 10 + str[i++]-'0';
		}
		res += (sign*num);
	}
	return res;
}

int main(void){
	ifstream file("input.txt");
	string line, word = "red";
	long long ans = 0, res = 0;
	while(file >> line){
		ans += processLine(line);
		res += parse_numbers(line);
	}
	cout << "Part 1: " << ans << "\n";
	cout << "Part 2: " << res << "\n";
}