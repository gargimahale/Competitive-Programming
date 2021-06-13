#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void fill(vector<vector<int>>& image, int i, int j, int oldColor, int newColor) {
        if (i >= image.size() || i < 0 || j < 0 || j >= image[0].size() || image[i][j] != oldColor) {
            return;
        }

        image[i][j] = newColor;

        // dfs call
        fill(image, i + 1, j, oldColor, newColor);
        fill(image, i - 1, j, oldColor, newColor);
        fill(image, i, j + 1, oldColor, newColor);
        fill(image, i, j - 1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;

        fill(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
};

// TC: O(N*M)
// SC: O(N*M)