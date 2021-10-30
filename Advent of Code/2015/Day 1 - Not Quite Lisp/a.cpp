#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	void getFloorNumber(string& text, int& floor){
		for (char ch: text){
			if (ch == '(') ++floor;
			else --floor;
		}
	}

	int getIndexForBasement(string& text){
		int count = 0;
		for (int i = 0; i < text.size(); ++i){
			count += (text[i] == '(' ? 1: -1);

			if (count < 0){
				return i + 1;
			}
		}
		return 0;
	}
};

int main(void){
	Solution sol;
	ifstream myFile("input.txt");
	string input;
	myFile >> input;

	// int floor = 0;
	// sol.getFloorNumber(input, floor);
	// cout << floor << "\n";

	cout << sol.getIndexForBasement(input) << "\n";
}