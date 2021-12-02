#include <bits/stdc++.h>
using namespace std;

int main(void){
	ifstream myFile("input.txt");
	string way;
	int steps;

	int x = 0, y = 0, aim = 0;

	while(myFile >> way){
		myFile >> steps;

		if (way == "forward"){
			x += steps;
			y += (aim * steps);
		} 
		else if (way == "down") {
			aim += steps;
		}
		else if (way == "up") {
			aim -= steps;
		}
	}
	cout << "Part 2: " << x*y << "\n";
}