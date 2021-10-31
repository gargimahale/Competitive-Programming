#include <bits/stdc++.h>
using namespace std;


int getLightsOn(vector<vector<int>>& lights){
	int count = 0;
	for (int i = 0; i < 1000; ++i){
		for (int j = 0; j < 1000; ++j){
			count += lights[i][j];
		}
	}
	return count;
}

void toggle_lights(int& x1, int& y1, int& x2, int& y2, vector<vector<int>>& lights){
	for (int i = x1; i <= x2; ++i){
		for (int j = y1; j <= y2; ++j){
			lights[i][j] += 2;
		}
	}
}

void turn_off(int& x1, int& y1, int& x2, int& y2, vector<vector<int>>& lights){
	for (int i = x1; i <= x2; ++i){
		for (int j = y1; j <= y2; ++j){
			lights[i][j] -= 1;
			if (lights[i][j] < 0){
				lights[i][j] = 0;
			}
		}
	}
}

void turn_on(int& x1, int& y1, int& x2, int& y2, vector<vector<int>>& lights){
	for (int i = x1; i <= x2; ++i){
		for (int j = y1; j <= y2; ++j){
			lights[i][j] += 1;
		}
	}
}

int main(void){
	vector<vector<int>> lights(1000, vector<int> (1000));
	string input;
	ifstream myFile("input.txt");

	while(getline(myFile, input)){
		istringstream iss(input);
		string command;
		iss >> command;

		if (command.compare("turn") == 0){
			iss >> command;
		}

		int x1, x2, y1, y2;
		string tmp1, tmp2, tmp3;
		iss >> tmp1 >> tmp2 >> tmp3;

		istringstream cs1(tmp1);
		istringstream cs2(tmp3);
		string each;

		getline(cs1, each, ',');
		x1 = stoi(each);
		getline(cs1, each, ',');
		y1 = stoi(each);
		getline(cs2, each, ',');
		x2 = stoi(each);
		getline(cs2, each, ',');
		y2 = stoi(each);

		if (command.compare("toggle") == 0){
			toggle_lights(x1, y1, x2, y2, lights);
		}

		if (command.compare("off") == 0){
			turn_off(x1, y1, x2, y2, lights);
		}

		if (command.compare("on") == 0){
			turn_on(x1, y1, x2, y2, lights);
		}
	}
	cout << getLightsOn(lights) << "\n";
}