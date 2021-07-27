#include <bits/stdc++.h>
using namespace std;

class Vector2D {
public:

    vector<vector<int>> vec;
    int row, col, size;

    Vector2D(vector<vector<int>>& vec) {
        this->vec = vec;
        row = 0, col = 0, size = vec.size();
    }

    int next() {
        if (hasNext())
            return vec[row][col++];
        return -1;
    }

    bool hasNext() {
        while (row < size && col == vec[row].size()) {
            ++row, col = 0;
        }
        return  row < size;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
