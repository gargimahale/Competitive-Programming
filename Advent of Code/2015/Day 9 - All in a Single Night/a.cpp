#include <bits/stdc++.h>
using namespace std;

void travel(const vector<string> &route, const vector<string> &cities,
	const map<pair<string, string>, int> &distances,
	const int current, vector<int> &results) {
		bool ended{true};
		for (auto &city : cities) {
		if (find(route.begin(), route.end(), city) == route.end()) {
			auto new_route = route;
			new_route.push_back(city);
			int new_distance = current;
			if (route.size()) {
				new_distance += distances.at({route.back(), city});
			}
			travel(new_route, cities, distances, new_distance, results);
			ended = false;
		}
	}

	if (ended) {
		results.push_back(current);
	}
}

void processFile(const char *filename) {
	ifstream f(filename);
	string line;

	map<pair<string, string>, int> distances;
	vector<string> cities;

	while (getline(f, line)) {
		string a, b;
		string str;
		int value;

		istringstream iss(line);

		iss >> a >> str >> b >> str >> value;

		distances[{a, b}] = value;
		distances[{b, a}] = value;
		cities.push_back(a);
		cities.push_back(b);
	}

	vector<int> results;
	sort(cities.begin(), cities.end());
	cities.erase(unique(cities.begin(), cities.end()), cities.end());

	travel({}, cities, distances, 0, results);

	sort(results.begin(), results.end());
	cout << "Shortest: " << results[0] << endl;
	cout << "Longest: " << results.back() << endl;
}

int main(void) {
	processFile("input.txt");
	return 0;
}