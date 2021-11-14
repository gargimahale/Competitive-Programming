#include <bits/stdc++.h>
using namespace std;

bool satisfiesCriteria(unsigned int e){
	string str = to_string(e);
	char lastDigit;

	if (str.length() != 6) return 0;
	lastDigit = str[0];

	// checks if two adj letter are same
	bool foundAdj = false;
	int countAdj = 1;
	for (int i = 1; i < str.size(); ++i){
		if (str[i] == lastDigit){
			++countAdj;
			if (countAdj == 2 && i == str.size()-1)
				foundAdj = true;
		}
		else{
			if (countAdj == 2){
				foundAdj = true;
				break;
			}
			countAdj = 1;
		}
		lastDigit = str[i];
	}

	if (!foundAdj) return 0;

	// Check if the seq never decreases from left to right
	lastDigit = str[0];
	bool foundDecr = false;

	for (int i = 1; i < str.size(); ++i){
		if (str[i] < lastDigit){
			foundDecr = true;
			break;
		}
		lastDigit = str[i];
	}

	if (foundDecr) return 0;

	return true;
}

int main(){
	int start = 353096;
	int end = 843212;

	int count = 0;
	for (int i = start; i <= end; ++i){
		if (satisfiesCriteria(i))
			++count;
	}

	cout << "Part 1: " << count << "\n";

}

