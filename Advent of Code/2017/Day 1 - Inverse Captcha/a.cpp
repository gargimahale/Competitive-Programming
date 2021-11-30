#include <bits/stdc++.h>
using namespace std;

unsigned char_to_int(char ch) {
    return ch - '0';
}

int main(void) {
    uint64_t sum = 0;
    char next;

    if (cin >> next) {
        unsigned first = char_to_int(next);
        unsigned last = first, count = 1;

        while (cin >> next) {
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
    cout << sum << "\n";
}