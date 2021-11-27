#include <bits/stdc++.h>
using namespace std;

int main(void){
	unsigned char direction;
	unsigned int delta;
	long x = 0, y = 0, xFinal = 0, yFinal = 0;
	int index;
	string input, move;

	vector <int> xPos, yPos;
	ifstream in_stream("input.txt");

	if(in_stream.is_open())
		getline(in_stream, input);

	while(true){
		index = input.find_first_of(',');
		if(index == string::npos){
			move = input;

			if(move[0] == 'R'){
				direction = (direction + 1) % 4;
			}

			else{
				if(direction == 0){
					direction = 3;
				}
				else
					--direction;
			}

			move.erase(0, 1);
			delta = stoi(move);

			switch (direction){
				case 0:
					y += delta;
					break;

				case 1:
					x += delta;
					break;

				case 2:
					y -= delta;
					break;

				case 3:
					x -= delta;
			}
			break;
		}

		move = input.substr(0, index);
		input.erase(0, index + 2);

		if(move[0] == 'R'){
			direction = (direction + 1)%4;
		}
		else{
			if(direction == 0){
				direction = 3;
			}
			else
				direction--;
		}

		move.erase(0, 1);
		delta = stoi(move);

		while (delta > 0){
			switch (direction){
				case 0:
					++y;
					break;

				case 1:
					++x;
					break;

				case 2:
					--y;
					break;

				case 3:
					--x;
					break;
			}

			--delta;

			for(int i = 0; i < xPos.size(); i++){
				if((x == xPos.at(i)) && (y == yPos.at(i))){
					xFinal = xPos.at(i);
					yFinal = yPos.at(i);
					cout << abs(xFinal) + abs(yFinal) << endl;
					exit(0);
					break;
				}
			}
			xPos.push_back(x);
			yPos.push_back(y);
		}
	}
	cout << abs(xFinal)+abs(yFinal) << "\n";
}