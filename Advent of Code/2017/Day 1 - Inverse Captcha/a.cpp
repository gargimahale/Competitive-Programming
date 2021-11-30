#include <bits/stdc++.h>
using namespace std;

unsigned char_to_int(char ch) {
    return ch - '0';
}

void part1(const string& text){
	uint64_t sum = 0;
    char next;
	istringstream iss(text);

    if (iss >> next) {
        unsigned first = char_to_int(next);
        unsigned last = first, count = 1;

        while (iss >> next) {
            ++count;
            unsigned x = char_to_int(next);
            if (last == x) {
                sum += x;
            }
            last = x;
        }

        if (count > 1 && last == first) {
            sum += first;
        }
    }
    cout << "Part 1: " << sum << "\n";
}

void part2(const string& text){
	uint64_t sum = 0;
	vector<unsigned> numbers;

	for (int i = 0; i < text.size(); ++i)
		numbers.push_back(char_to_int(text[i]));

	size_t n = numbers.size()/2;
	for (size_t i = 0; i < numbers.size(); ++i){
		if (numbers[i] == numbers[(i+n) % numbers.size()]){
			sum += numbers[i];
		}
	}
	cout << "Part 2: " << sum << "\n"; 
}

int main(void) {
    string text;
    ifstream myFile("input.txt");
    myFile >> text;

    part1(text);
    part2(text);
}