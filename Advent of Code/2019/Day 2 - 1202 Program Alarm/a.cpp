#include <bits/stdc++.h>
using namespace std;

int processVector(vector<unsigned int> codes, unsigned int noun, unsigned int verb){
	codes[1] = noun;
	codes[2] = verb;
	for (int i = 0; i < codes.size(); i += 4){
		if (codes[i] == 1)
			codes[codes[i+3]] = codes[codes[i+1]] + codes[codes[i+2]];
		else if (codes[i] == 2)
			codes[codes[i+3]] = codes[codes[i+1]] * codes[codes[i+2]];
		else break;
	}
	return codes[0];
}

int main(){
	vector<unsigned int> codes;
	ifstream file("input.txt");
	string numberStr;

	while(getline(file, numberStr, ',')){
		codes.push_back(stoul(numberStr));
	}

	file.close();

	cout << "Part 1: " << processVector(codes, 12, 2) << "\n";

	// Part 2
	for (int noun = 0; noun < 100; ++noun){
		for (int verb = 0; verb < 100; ++verb){
			if (processVector(codes, noun, verb) == 19690720){
				cout << "Part 2: " << 100 * noun + verb << "\n";
				return 0;
			}
		}
	}
}

