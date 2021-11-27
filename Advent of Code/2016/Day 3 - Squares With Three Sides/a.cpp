#include <bits/stdc++.h>
using namespace std;


void process1(const string& filename){
	ifstream myFile(filename);
	int a, b, c, possible = 0;

	while(myFile >> a >> b >> c){
		int max = std::max({a, b, c});
		if (a + b + c - max > max){
			++possible;
		}
	}

	cout << possible << "\n";
}


void process2(const string& filename){
	ifstream myFile(filename);
	int a, b, c, possible = 0;
	
	vector<int> first, second, third;
	while(myFile >> a >> b >> c){
		first.push_back(a);
		second.push_back(b);
		third.push_back(c);
	}

	vector<int> sides(first.begin(), first.end());
	sides.insert(sides.end(), second.begin(), second.end());
	sides.insert(sides.end(), third.begin(), third.end());
	
	for (int i = 0; i < sides.size()-2; i += 3){
		a = sides[i]
		int max = std::max({a, b, c});

		if (a + b + c - max > max){
			++possible;
		}
	}
	cout << possible << "\n";
}

int main(void){
	process1("input.txt");
	process2("input.txt");
}