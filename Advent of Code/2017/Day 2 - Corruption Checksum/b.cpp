#include <bits/stdc++.h>
using namespace std;

int main(void) {
    uint64_t sum = 0;
    string line;
    ifstream myFile("input.txt");

    while (getline(myFile, line)) {

        istringstream tokenizer(line);
        int val = 0;
        vector<int> nums;

        while (tokenizer >> val) {
            nums.push_back(val);
        }

        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j) {
                int a = max(nums[i], nums[j]);
                int b = min(nums[i], nums[j]);
                if (a % b == 0) {
                    sum += a / b;
                    break;
                }
            }
    }

    cout << "Part 2: " << sum << "\n";
}