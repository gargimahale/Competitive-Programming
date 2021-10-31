#include <bits/stdc++.h>
using namespace std;

int main(void){
	ifstream file("input.txt");
	string text;
	file >> text;

	pair<int, int> pos = {0, 0};
	set<pair<int, int>> mp;
	mp.insert(pos);
	
	int count = 1;

	for (int i = 0; i < text.size(); ++i){
		
		switch(text[i]){
			case '^':
					pos.first--;
					break;

			case '>':
					pos.second++;
					break;

			case 'v':
					pos.first++;
					break;

			case '<':
				pos.second--;
				break;
		}

		if (mp.count(pos) == 0){
			++count;
			mp.insert(pos);
		}
	}

	cout << count << "\n"; 
}