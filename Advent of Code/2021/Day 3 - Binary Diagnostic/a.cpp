#include <bits/stdc++.h>
using namespace std;

vector<string> process1(const vector<string>& codes){
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
	cout << gamma << " " << epsilon << "\n";
	cout << "Part 1: " << (long long)stoi(gamma, 0, 2) * stoi(epsilon, 0, 2) << "\n";
	return {gamma, epsilon};
}

void process2(const vector<string>& codes, const vector<string>& bits){
	string gamma = bits[0];
	string epsilon = bits[1];

	vector<string> oxygen, co2;

	for (int i = 0; i < 1; ++i){
		for (int j = 0; j < codes.size(); ++j){
			if (codes[j][i] == gamma[i]){
				oxygen.push_back(codes[j]);
			}
			else{
				co2.push_back(codes[j]);
			}
		}
	}
	// cout << oxygen.size() << "\n";

	// oxygen
	for (int i = 1; i < 9; ++i){
		vector<string> temp;
		for (int j = 0; j < oxygen.size(); ++j){
			if (oxygen[j][i] == gamma[i]){
				temp.push_back(oxygen[j]);
			}
		}
		// cout << i << " " << oxygen.size() << "\n";
		swap(temp, oxygen);
	}

	cout << oxygen[0] << " " << oxygen[1] << "\n";
}

int main(void){
	ifstream myFile("input.txt");
	vector<string> codes;
	string text;

	while(myFile >> text){
		codes.push_back(text);
	}	
	
	vector<string> bits = process1(codes);
	process2(codes, bits);
}