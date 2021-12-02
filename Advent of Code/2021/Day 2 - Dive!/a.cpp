#include <bits/stdc++.h>
using namespace std;

int main(void){
	ifstream myFile("input.txt");
	string way;
	int steps;

	int x = 0, y = 0;

	while(myFile >> way){
		myFile >> steps;

		if (way == "forward") x += steps;
		else if (way == "down") y += steps;
		else if (way == "up") y -= steps;
		else x -= steps;
	}
	cout << "Part 1: " << x*y << "\n";
}