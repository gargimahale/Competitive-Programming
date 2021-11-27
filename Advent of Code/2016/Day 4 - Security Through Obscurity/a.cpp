#include <bits/stdc++.h>
using namespace std;

struct cn{
	char c;
	int n;

	bool operator<(const cn& o) const{
		return (n > o.n) || (n == o.n && c < o.c);
	}
};

int decode(const string& s){
	vector<cn> chars;

	for (char c = 'a'; c <= 'z'; ++c){
		chars.push_back({c, 0});
	}

	int id = 0, chk = -1;
	for (auto c: s){
		if (chk >= 0){
			if (isalpha(c)){
				if (chars[chk].c != c) return 0;
				++chk;
			}
		}
		else if (isalpha(c)) {
			chars[c-'a'].n++;
		}
		else if (isdigit(c)){
			id = id * 10 + (c - '0');
		}
		else if (c == '['){
			chk = 0;
			sort(begin(chars), end(chars));
		}
	}
	return id;
}

void process(const string& filename){
	string line;
	int result = 0;
	ifstream myFile(filename);

	while(getline(myFile, line)){
		result += decode(line);
	}
	cout << result << "\n";
}

void rotate(std::string& s, int d) {
    for (auto& c: s) {
        if (c != ' ') { 
        	c = char('a' + ((int(c - 'a') + d) % 26)); 
        }
    }
}

void decode1(const string& s){
	vector<cn> chars;

	for (char c = 'a'; c <= 'z'; ++c){
		chars.push_back({c, 0});
	}

	int id = 0, chk = -1;
	string name;

	for (auto c: s){
		if (chk >= 0){
			if (isalpha(c)){
				if (chars[chk].c != c) return;
				++chk;
			}
		}
		else if (isalpha(c)) {
			chars[c-'a'].n++;
			name += c;
		}
		else if (c == '-') {
			name += ' ';
		}
		else if (isdigit(c)){
			id = id * 10 + (c - '0');
		}
		else if (c == '['){
			chk = 0;
			sort(begin(chars), end(chars));
		}
	}

	rotate(name, id);
	if (name.find("north") != string::npos){
		cout << name << " " << id << endl;
	}
}

void process1(const string& filename){
	string line;
	ifstream myFile(filename);

	while(getline(myFile, line)){
		decode1(line);
	}
}

int main(void){
	process("input.txt");
	process1("input.txt");
}