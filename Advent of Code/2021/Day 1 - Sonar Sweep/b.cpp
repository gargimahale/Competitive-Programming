#include <bits/stdc++.h>
using namespace std;

int main(void){
	ifstream myFile("input.txt");
	int val, inc = 0;

	vector<int> readings;
	while(myFile >> val) readings.push_back(val);

	for (int i = 0; i < readings.size()-1; i++){
		int s1 = readings[i] + readings[i+1] + readings[i+2];
		int s2 = readings[i+1] + readings[i+2] + readings[i+3];

		if (s2 > s1){
			++inc;
		}
	}
	cout << "Part 2: " << inc << "\n";
}