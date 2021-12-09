#include <bits/stdc++.h>
using namespace std;

struct Bot{
	int low;
	int high;

	Bot(){
		low = 0;
		high = 0;
	}

	void take(int value){
		if(low == 0){
			low = value;
			return;
		}
		if(value < low){
			high = low;
			low = value;
		}
		else{
			high = value;
		}
	}

	friend ostream& operator<< (ostream& out, const Bot& bot);
};

ostream& operator<< (ostream& out, const Bot& bot){
	out << "Bot has a low value of " << bot.low << " and a high value of " << bot.high;
	return out;
}

int main(void){
	map<int, Bot> bots;
	ifstream fh("input.txt");
	string line;
	list<string> instructions;
	while(getline(fh, line)){
		if(line.find("value ") == 0){
			int value;
			int bot;
			sscanf(line.c_str(), "value %d goes to bot %d", &value, &bot);
			bots[bot].take(value);
		}
		else{
			instructions.push_back(line);
		}
	}

	map<int, int> outputs;
	while(!instructions.empty()){
		vector<list<string>::iterator> to_remove;
		for(auto instruction = instructions.begin(); instruction != instructions.end(); instruction++){
			int giver, low, high;
			char dest_1_str[100], dest_2_str[100];
			sscanf(instruction->c_str(), "bot %d gives low to %s %d and high to %s %d", &giver, dest_1_str, &low, dest_2_str, &high);
			if(bots[giver].low == 0 || bots[giver].high == 0)
				continue;
			string dest_1(dest_1_str);
			string dest_2(dest_2_str);
			if(dest_1 == "bot")
				bots[low].take(bots[giver].low);
			else
				outputs[low] += bots[giver].low;
			if(dest_2 == "bot")
				bots[high].take(bots[giver].high);
			else
				outputs[high] += bots[giver].high;
			bots[giver].low = 0;
			bots[giver].high = 0;
			to_remove.push_back(instruction);
		}
		for(auto& r: to_remove)
			instructions.erase(r);
	}
	cout << outputs[0] * outputs[1] * outputs[2] << endl;
	cout << "Done" << endl;
}