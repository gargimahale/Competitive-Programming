#include <bits/stdc++.h>
using namespace std;

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution{
public:
    int search(const ArrayReader &reader, int target){
        if (reader.get(0) == target)
            return 0;

        // find bounds
        int l = 0, r = 1;
        while (reader.get(r) < target){
            l = r;
            r *= 2;
        }

        while (l <= r){
            int m = l + (r - l) / 2;
            if (reader.get(m) == target)
                return m;
            else if (reader.get(m) < target)
                l = m + 1;
            else
                r = m - 1;
        }
        return -1;
    }
};