#include <bits/stdc++.h>
using namespace std;

class RLEIterator {
public:
    vector<int> encoding;
    int i = 0;

    RLEIterator(vector<int>& encoding) {
        this->encoding = encoding;
        i = 0;
    }

    int next(int n) {
        while (i < encoding.size()) {
            if (encoding[i] >= n) {
                encoding[i] -= n;
                return encoding[i + 1];
            }
            else {
                n -= encoding[i];
                i += 2;
            }
        }
        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */