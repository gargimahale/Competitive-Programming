#include <bits/stdc++.h>
using namespace std;

void P1(istream& input);
void P2(istream& input);
void ways(int32_t target, size_t index, vector<uint32_t>& packages, unordered_set<uint32_t>& used, unordered_set<uint32_t>& best, bool trio = false);
bool waysPair(int32_t target, int32_t index, vector<uint32_t>& packages, const unordered_set<uint32_t>& skip, uint32_t a, uint32_t b);
bool waysTrio(uint32_t target, int32_t index, vector<uint32_t>& packages, const unordered_set<uint32_t>& skip, uint32_t a[2], uint32_t b[2], uint32_t c[2]);
uint64_t qe(const unordered_set<uint32_t>& packages);
uint64_t sum(const vector<uint32_t>& v);
uint64_t sum(const unordered_set<uint32_t>& s);
void print(const unordered_set<uint32_t>& s);

int main(void) {

    istringstream test1(R"(1 2 3 4 5 7 8 9 10 11)"); // p1: 99, p2: 44

    istringstream test2(R"(1 2 3 6 7 8 9 11 16)"); // p1: 96

    istringstream test3(R"(1 2 3 5 7 13 17 19 23 29 31 37 41 43 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113)"); // p1: 

    istringstream test4(R"(1 3 5 11 13 17 19 23 29 31 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113)"); // p1: 11266889531, p2: 77387711


    ifstream infile("input.txt");
    P1(infile);

    infile.clear();
    infile.seekg(0);

    P2(infile);
}

void P1(istream& input) {

    vector<uint32_t> packages;

    uint32_t n;
    while (input >> n) {
        packages.push_back(n);
    }

    sort(packages.begin(), packages.end(), greater<uint32_t>());

    unordered_set<uint32_t> used;
    unordered_set<uint32_t> result;

    ways(sum(packages)/3, 0, packages, used, result);

    cout << "Smallest 3-way QE: " << qe(result) << endl;
}

void P2(istream& input) {

    vector<uint32_t> packages;

    uint32_t n;
    while (input >> n) {
        packages.push_back(n);
    }

    sort(packages.begin(), packages.end(), greater<uint32_t>());

    unordered_set<uint32_t> used;
    unordered_set<uint32_t> result;

    ways(sum(packages)/4, 0, packages, used, result, true);

    // print(result);

    cout << "Smallest 4-way QE: " << qe(result) << endl;
}

void ways(int32_t target, size_t index, vector<uint32_t>& packages, unordered_set<uint32_t>& used, unordered_set<uint32_t>& best, bool trio /* = false */) {

    if (target < 0 || (trio ? 4 : 3) * used.size() > packages.size() || (target != 0 && index >= packages.size())) {
        return;
    }

    if (best.size() != 0 && used.size() > best.size()) {
        return;
    }

    if (target == 0) {

        if (best.size() == 0 || used.size() < best.size() || (used.size() == best.size() && qe(used) < qe(best))) {

            if (trio) {
                uint32_t usedA[2] = {};
                uint32_t usedB[2] = {};
                uint32_t usedC[2] = {};

                if (waysTrio(sum(used), packages.size()-1, packages, used, usedA, usedB, usedC)) {
                    // print(used);
                    best = used;
                }
            } else if (waysPair(sum(used), packages.size()-1, packages, used, 0, 0)) {
                // print(used);
                best = used;
            }
        }

        return;
    }

    auto current = packages[index];

    used.insert(current);
    ways(target - current, index+1, packages, used, best, trio);
    used.erase(current);

    ways(target, index+1, packages, used, best, trio);

    return;
}

bool waysPair(int32_t target, int32_t index, vector<uint32_t>& packages, const unordered_set<uint32_t>& skip, uint32_t a, uint32_t b) {

    if (target <= 0 || index < 0) {
        if (target != 0 || skip.size() + a + b != packages.size()) {
            return false;
        }

        if (skip.size() > a || skip.size() > b) {
            return false;
        }

        return true;
    }

    bool found = false;

    auto current = packages[index];
    if (skip.find(current) != skip.end()) {
        found = waysPair(target, index-1, packages, skip, a, b);
    } else {

        found = waysPair(target, index-1, packages, skip, a+1, b);
        if (found) {
            return found;
        }

        found = waysPair(target - current, index-1, packages, skip, a, b+1);
    }

    return found;
}

bool waysTrio(uint32_t target, int32_t index, vector<uint32_t>& packages, const unordered_set<uint32_t>& skip, uint32_t a[2], uint32_t b[2], uint32_t c[2]) {

    if (a[1] > target || b[1] > target || c[1] > target) {
        return false;
    }

    if (index < 0) {
        if (skip.size() + a[0] + b[0] + c[0] != packages.size()) {
            return false;
        }

        if (skip.size() > a[0] || skip.size() > b[0] || skip.size() > c[0]) {
            return false;
        }

        if (a[1] != b[1] || b[1] != c[1]) {
            return false;
        }

        return true;
    }

    bool found = false;

    auto current = packages[index];
    if (skip.find(current) != skip.end()) {
        found = waysTrio(target, index-1, packages, skip, a, b, c);
    } else {

        a[0]++, a[1] += current;
        found = waysTrio(target, index-1, packages, skip, a, b, c);
        a[0]--, a[1] -= current;
        if (found) {
            return found;
        }

        b[0]++, b[1] += current;
        found = waysTrio(target, index-1, packages, skip, a, b, c);
        b[0]--, b[1] -= current;
        if (found) {
            return found;
        }

        c[0]++, c[1] += current;
        found = waysTrio(target, index-1, packages, skip, a, b, c);
        c[0]--, c[1] -= current;
    }

    return found;
}

uint64_t qe(const unordered_set<uint32_t>& packages) {

    uint64_t product = 1;

    for (const auto& w : packages) {
        product *= w;
    }

    return product;
}

uint64_t sum(const vector<uint32_t>& v) {
    return accumulate(v.begin(), v.end(), 0);
}

uint64_t sum(const unordered_set<uint32_t>& s) {
    return accumulate(s.begin(), s.end(), 0);
}

void print(const unordered_set<uint32_t>& s) {

    uint64_t sum = 0, qe = 1;

    for (const auto& w : s) {
        cout << w << " ";
        sum += w;
        qe *= w;
    }

    cout << " = " << sum << " : " << qe << endl;
}