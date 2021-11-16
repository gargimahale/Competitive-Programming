#include <bits/stdc++.h>
using namespace std;

int main(void){

	int num;
	ifstream file("input.txt");

	int resultant = 0, ans;
	bool found = false;

	unordered_set<int> seen{0};

	while(file >> num){
		resultant += num;
		if (seen.insert(resultant).second && !found){
			found = true;
			ans = resultant;
		}
	}
	
	cout << "Part 1: " << resultant << "\n";
	cout << "Part 2: " << ans << "\n";
}