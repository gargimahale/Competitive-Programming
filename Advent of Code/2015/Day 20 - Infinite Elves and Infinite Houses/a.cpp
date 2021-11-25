#include <bits/stdc++.h>
using namespace std;

void part1(const int target) {
    int h{0};

    while (true) {
        int r{0};

        auto sqrh = (int)sqrt(h);

        for (int i{1}; i <= sqrh; ++i) {
            if (h % i == 0) {
                r += i * 10;
                r += (h / i) * 10;
            }
        }

        if (r >= target) {
            cout << "part1: " << h << "\n";
            return;
        }
        ++h;
    }
}

void part2(const int target) {
    map<int, int> houses;

    int e{1};
    while (e < 1000000) {
        int p{e * 11};

        for (int h{e}, i{0}; i < 50; h += e, ++i) {
            houses[h] += p;
        }

        ++e;
    }

    int best = 0;
    for (int i{1}; i < 1000000; ++i) {
        auto hh = houses[i];

        if (hh >= target) {
            best = i;
            break;
        }
    }

    cout << "part2: " << best << "\n";
}

int main(void) {
    part1(34000000);
    part2(34000000);
}