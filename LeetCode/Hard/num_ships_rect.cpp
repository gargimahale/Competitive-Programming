#include <bits/stdc++.h>

using namespace std;

/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {
        int x2 = topRight[0], y2 = topRight[1], x1 = bottomLeft[0], y1 = bottomLeft[1];
        if (x1 > x2 || y1 > y2) {
            return 0;
        }
        int ships = sea.hasShips(topRight, bottomLeft);
        if (x1 == x2 && y1 == y2 || ships == 0) {
            return ships;
        }

        return (countShips(sea, {x2, y2}, {(x1 + x2) / 2 + 1, (y1 + y2) / 2 + 1}) + countShips(sea, {(x1 + x2) / 2, y2}, {x1, (y1 + y2) / 2 + 1}) + countShips(sea, {(x1 + x2) / 2, (y1 + y2) / 2}, {x1, y1})) + countShips(sea, {x2, (y1 + y2) / 2}, {(x1 + x2) / 2 + 1, y1});
    }
};