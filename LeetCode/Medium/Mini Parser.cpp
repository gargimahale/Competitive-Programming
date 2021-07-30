#include <bits/stdc++.h>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {

    NestedInteger parse(const string& s, int& pos) {
        if (s[pos] == '[') {
            return parseList(s, pos);
        }
        return parseNum(s, pos);
    }

    NestedInteger parseNum(const string& s, int& pos) {
        int num = 0;
        int sign = 1;
        if (s[pos] == '-' || s[pos] == '+') {
            if (s[pos] == '-') {
                sign = -1;
            }
            ++pos;
        }

        while (pos < s.size() && isdigit(s[pos])) {
            num = num * 10 + (s[pos++] - '0');
        }

        return NestedInteger(sign * num);
    }


    NestedInteger parseList(const string& s, int& pos) {
        NestedInteger ni;
        while (s[pos] != ']') {
            ++pos;
            if (s[pos] == ']') break;
            ni.add(parse(s, pos));
        }
        ++pos;
        return ni;
    }

public:
    NestedInteger deserialize(string s) {
        int pos = 0;
        return parse(s, pos);
    }
};