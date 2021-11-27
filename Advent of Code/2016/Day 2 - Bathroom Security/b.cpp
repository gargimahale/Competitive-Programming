#include <bits/stdc++.h>
using namespace std;

int main(void){
	ifstream myFile("input.txt");
	vector<string> input;
	string in, line;

	while(getline(myFile, in)){
		input.push_back(in);
	}

	char keyPad[5][5] = {{'x', 'x', '1', 'x', 'x'},
						 {'x', '2', '3', '4', 'x'},
						 {'5', '6', '7', '8', '9'}, 
						 {'x', 'A', 'B', 'C', 'x'},
						 {'x', 'x', 'D', 'x', 'x'}};

	unsigned char x = 1, y = 1;
	for (unsigned int i = 0; i < input.size(); ++i){
		line = input.at(i);

		for (int j = 0; j < line.size(); ++j){
			if (line.at(j) == 'U'){
				if (y != 0){
					--y;
					if (keyPad[x][y] == 'x'){
						++y;
					}
				}
			}

			if (line.at(j) == 'D'){
				if (y != 4){
					++y;
					if (keyPad[x][y] == 'x'){
						--y;
					}
				}
			}

			if (line.at(j) == 'L'){
				if (x != 0){
					--x;
					if (keyPad[x][y] == 'x'){
						++x;
					}
				}
			}

			if (line.at(j) == 'R'){
				if (x != 4){
					++x;
					if (keyPad[x][y] == 'x'){
						--x;
					}
				}
			}
		}
		cout << keyPad[y][x];
	}
	cout << "\n";
}