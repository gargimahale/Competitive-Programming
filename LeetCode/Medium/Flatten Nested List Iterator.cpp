#include <bits/stdc++.h>
using namespace std;

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    queue<int> Q;
    void go(const vector<NestedInteger>& A) {
        for (auto x : A) {
            if (x.isInteger()) {
                Q.push(x.getInteger());
            } else {
                go(x.getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &A) {
        go(A);
    }

    int next() {
        auto i = Q.front(); Q.pop();
        return i;
    }

    bool hasNext() {
        return !Q.empty();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
