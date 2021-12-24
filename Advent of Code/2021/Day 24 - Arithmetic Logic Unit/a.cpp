#include <bits/stdc++.h>
using namespace std;

int64_t search(vector<int32_t> &divisors, vector<int32_t> &offsets, vector<int32_t> &modifiers, auto op) {
    unordered_map<int64_t, int64_t> z_values;
    unordered_map<int64_t, int64_t> z_values_new;
    z_values.insert(make_pair(0, 0));

    for (int64_t index = 0; index < 14; index++) {
        for (auto z0 : z_values) {
            for (int64_t digit = 9; digit > 0; digit--) {
                int64_t candidate = z0.second * 10 + digit;
                int64_t z = z0.first / divisors[index];

                if (z0.first % 26 + offsets[index] != digit)
                    z = z * 26 + digit + modifiers[index];

                auto [it, flag] = z_values_new.emplace(z, candidate);

                if (!flag)
                    it->second = op(it->second, candidate);
            }
        }
        z_values = move(z_values_new);
    }
    return z_values[0];
}

int main(void) {
    ifstream input("input.txt");

    vector<int32_t> divisors;
    vector<int32_t> offsets;
    vector<int32_t> modifiers;

    string line;
    size_t block_id = 0;
    size_t line_id = 0;

    while (getline(input, line)) {
        if (line_id == 4) {
            int32_t val = stol(line.substr(6));
            divisors.push_back(val);
        }

        if (line_id == 5) {
            int32_t val = stol(line.substr(6));
            offsets.push_back(val);
        }

        if (line_id == 15) {
            int32_t val = stol(line.substr(6));
            modifiers.push_back(val);
        }

        line_id++;
        block_id += line_id / 18;
        line_id %= 18;
    }

    cout << "Highest valid number: " << search(divisors, offsets, modifiers, [](uint64_t a, uint64_t b) { return max(a, b); }) << "\n";
    cout << "Lowest valid number: " << search(divisors, offsets, modifiers, [](uint64_t a, uint64_t b) { return min(a, b); }) << "\n";
}