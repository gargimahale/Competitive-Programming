#include <bits/stdc++.h>
using namespace std;

string inc(const string& str){
	string output = str;
	int c1 = str.size()-1;

	while(true){
		char ch = output.at(c1);
		char nc = ch + 1;

		if ((nc-'z') == 1){
			output.at(c1) = 'a';
			--c1;
		}
		else{
			output.at(c1) = nc;
			break;
		}
	}
	return output;
}

bool check_vowels(const string& str){
	if (! ( (str.find('o')!=std::string::npos) || 
        (str.find('i')!=std::string::npos) || 
        (str.find('l')!=std::string::npos) )){
		return true;
	}
	return false;
}

bool check_increasing(const string& str){
	for (int i = 2; i < 8; ++i){
		if (((str[i] - str[i-1]) == 1) && ((str[i-1]-str[i-2]) == 1)){
			return true;
		}
	}
	return false;
}

bool check_doubles(const string& str){
	int double_counter = 0;
	for (int i = 2; i < 8; ++i){
		if ((str[i] - str[i-1]) == 0){
			++double_counter;
			++i;
		}
	}
	return double_counter == 2;
}

bool check(const string& str){
	return check_doubles(str) && check_increasing(str) && check_vowels(str);
}

int main(void){
	string input = "cqjxjnds";
	string output = input;

	for (int i = 0; i < 2; ++i){
		while(!check(output)){
			output = inc(output);
		}

		cout << "Part " << i+1 << ": " << output << "\n";
		output = inc(output);
	}
}