#include <bits/stdc++.h>
using namespace std;

int main(void){
	ifstream myFile("input.txt");
	string line;
	uint64_t sum = 0;

	while(getline(myFile, line)){
		istringstream iss(line);

		int val = 0;
		int large = INT_MIN;
		int small = INT_MAX;

		while(iss >> val){
			large = max(large, val);
			small = min(small, val);
		}
		sum += (large-small);
	}
	cout << "Part 1: " << sum << "\n";
}