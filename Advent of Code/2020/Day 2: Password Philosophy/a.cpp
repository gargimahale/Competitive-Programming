#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream myfile("inp.txt");
    int input, target = 2020;
    vector<int> nums;
    while (myfile >> input) {
        nums.push_back(input);
    }
    threeSum(nums, target);
    return 0;
}