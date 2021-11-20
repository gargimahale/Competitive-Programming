#include <bits/stdc++.h>
using namespace std;

struct Ingredient {
	string name;
	int capacity;
	int durability;
	int flavor;
	int texture;
	int calories;

	void log() {
		cout << name << endl;
		cout << capacity << endl;
		cout << durability << endl;
		cout << flavor << endl;
		cout << texture << endl;
		cout << calories << endl;
	}
};

struct Recipe {
	vector<int> quantities;

	static void build(const vector<Ingredient> &ingredients, const vector<int> &quantities, Recipe &best,
	int &best_score) {
		int current = accumulate(quantities.begin(), quantities.end(), 0);

		if (current < 100) {
			if (quantities.size() < ingredients.size()) {
				for (int i = 0; i <= 100 - current; ++i) {
					auto new_quantities = quantities;
					new_quantities.push_back(i);
					build(ingredients, new_quantities, best, best_score);
				}
			}
		} 
		else {
			int score = 0;
			int c{0}, d{0}, f{0}, t{0}, cal{0};

			for (size_t i = 0; i < quantities.size(); ++i) {
				int q = quantities[i];
				auto ing = ingredients[i];
				c += q * ing.capacity;
				d += q * ing.durability;
				f += q * ing.flavor;
				t += q * ing.texture;
				cal += q * ing.calories;
			}

			c = max(0, c);
			d = max(0, d);
			f = max(0, f);
			t = max(0, t);

			score = c * d * f * t;

			// Part 1
			if (score > best_score) {
			  best.quantities = quantities;
			  best_score = score;
			}

			// Part 2
			// if (cal == 500 && score > best_score) {
			// 	best.quantities = quantities;
			// 	best_score = score;
			// }
		}
	}
};

void processFile(const char *filename) {
	ifstream f(filename);
	string line, str;

	vector<Ingredient> ingredients;

	while (getline(f, line)) {
		istringstream iss(line);
		Ingredient ingredient;

		iss >> ingredient.name >> str >> ingredient.capacity >> str;
		iss >> str >> ingredient.durability >> str;
		iss >> str >> ingredient.flavor >> str;
		iss >> str >> ingredient.texture >> str;
		iss >> str >> ingredient.calories;

		ingredients.push_back(ingredient);
	}

	f.close();

	Recipe best;
	int best_score = 0;
	Recipe::build(ingredients, {}, best, best_score);
	cout << "Best is " << best_score << endl;
}

int main() {
	processFile("input.txt");
	return 0;
}