#include <bits/stdc++.h>
using namespace std;

using Links = map<pair<string, string>, int>;

struct Table {
	vector<string> seats;
	int happiness{0};

	static void build(const vector<string> &people,
	const vector<string> &seats,
	vector<Table> &result) {
		bool ended{true};
		for (auto &p : people) {
			if (find(seats.begin(), seats.end(), p) == seats.end()) {
				ended = false;
				auto seats_cpy = seats;
				seats_cpy.push_back(p);
				build(people, seats_cpy, result);
			}
		}

		if (ended) {
			Table t;
			t.seats = seats;
			result.push_back(t);
		}
	}

	void compute(const Links &links) {
		happiness = 0;
		for (size_t i = 0; i < seats.size(); ++i) {
			int h = i - 1;
			h = h < 0 ? h + seats.size() : h;

			auto &previous = seats[h];
			int j = i + 1;
			j %= seats.size();

			auto &next = seats[j];
			auto &current = seats[i];

			happiness += links.at({current, previous});
			happiness += links.at({current, next});
		}
	}
};

void processFile(const char *filename, const bool add_you = false) {
	ifstream f(filename);
	string line, str;
	string name1, name2, verb;
	vector<string> people;
	int value;
	Links links;

	while (getline(f, line)) {
		istringstream iss(line);
		iss >> name1 >> str >> verb >> value >> str >> str >> str >> str >> str >>
		str >> name2;

		name2.pop_back();

		if (verb == "lose") {
			value = -value;
		}

		links[{name1, name2}] = value;

		people.push_back(name1);
		people.push_back(name2);
	}

	sort(people.begin(), people.end());
	auto last = unique(people.begin(), people.end());
	people.erase(last, people.end());

	if (add_you) {
		for (auto &p : people) {
			links[{"you", p}] = 0;
			links[{p, "you"}] = 0;
		}
		people.push_back("you");
	}

	vector<Table> tables;
	Table::build(people, {}, tables);

	for (auto &t : tables) {
		t.compute(links);
	}

	sort(tables.begin(), tables.end(), [](auto &a, auto &b) { return a.happiness > b.happiness; });

	cout << tables[0].happiness << endl;
}

int main() {
	processFile("input.txt");
	processFile("input.txt", true);
	return 0;
}