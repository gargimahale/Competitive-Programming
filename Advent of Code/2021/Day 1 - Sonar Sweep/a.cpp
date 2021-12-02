#include <bits/stdc++.h>
using namespace std;

int main(void){
	ifstream myFile("input.txt");
	int val, prev, inc = 0;

	myFile >> prev;

	while(myFile >> val){
		if (val > prev){
			++inc;
		}
		prev = val;
	}

	cout << "Part 1: " << inc << "\n";
}