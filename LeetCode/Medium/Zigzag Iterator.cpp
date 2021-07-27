#include <bits/stdc++.h>
using namespace std;

class ZigzagIterator {
public:
    vector<int> v1, v2;
    int i = 0, j = 0, n = 0, m = 0;

    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        this->v1 = v1;
        this->v2 = v2;
        i = 0, j = 0;
        n = v1.size(), m = v2.size();
    }

    int next() {
        if ((i < n && ((i + j) % 2 == 0)) || j == m) {
            return v1[i++];
        }
        if ((j < m && ((i + j) % 2 == 1)) || i == n) {
            return v2[j++];
        }
        return -1;
    }

    bool hasNext() {
        return i < n || j < m;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */