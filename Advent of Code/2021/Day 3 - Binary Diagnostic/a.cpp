#include <bits/stdc++.h>
using namespace std;

void process1(const vector<string>& codes){
	string gamma, epsilon;

	for (int i = 0; i < 12; ++i){
		int ones = 0, zeroes = 0;
		for (int j = 0; j < codes.size(); ++j){
			if (codes[j][i] == '1') ++ones;
			else ++zeroes;
		}
		gamma += (ones > zeroes ? '1': '0');
		epsilon += (ones < zeroes ? '1': '0');
	}
	// cout << gamma << " " << epsilon << "\n";
	cout << "Part 1: " << (long long)stoi(gamma, 0, 2) * stoi(epsilon, 0, 2) << "\n";
}

vector<string> getValue(const vector<string>& v, int idx, bool mostCommon){
    int ones = 0;
    vector<string> o;
    vector<string> z;
    for(string s : v){
        switch(s[idx]){
            case '1':
                ones++;
                o.push_back(s);
                break;
            case '0':
                z.push_back(s);
                break;
        }
    }

    auto x = ceil(v.size()/2.0);
    if(mostCommon) return ones >= x ? o : z;
    return ones >= x ? z : o;
}

void process2(const vector<string>& codes){
	vector<string> curr = codes;
    vector<string> curr2 = codes;

    for(int i = 0; i < 12; i++){
        if (curr.size() != 1)
            curr = getValue(curr, i, true);

        if (curr2.size() != 1)
            curr2 = getValue(curr2, i, false);
    }

    string o2 = curr[0], co2 = curr2[0];
    int a = stoi(o2, nullptr, 2), b = stoi(co2, nullptr, 2);

    cout << "Part 2: " << a * b << "\n";
}

int main(void){
	ifstream myFile("input.txt");
	vector<string> codes;
	string text;

	while(myFile >> text){
		codes.push_back(text);
	}	
	
	process1(codes);
	process2(codes);
}