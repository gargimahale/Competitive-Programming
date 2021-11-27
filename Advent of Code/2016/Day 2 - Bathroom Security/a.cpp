#include <bits/stdc++.h>
using namespace std;

int main(void){
	ifstream myFile("input.txt");
	vector<string> input;
	string in, line;

	while(getline(myFile, in)){
		input.push_back(in);
	}

	int keyPad[3][3] = {{1, 2, 3},
						{4, 5, 6},
						{7, 8, 9}};

	unsigned char x = 1, y = 1;
	for (unsigned int i = 0; i < input.size(); ++i){
		line = input.at(i);

		for (int j = 0; j < line.size(); ++j){
			if (line.at(j) == 'U'){
				if (y != 0){
					--y;
				}
			}

			if (line.at(j) == 'D'){
				if (y != 2){
					++y;
				}
			}

			if (line.at(j) == 'L'){
				if (x != 0){
					--x;
				}
			}

			if (line.at(j) == 'R'){
				if (x != 2){
					++x;
				}
			}
		}
		cout << keyPad[y][x];
	}
	cout << "\n";
}