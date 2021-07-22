#include <bits/stdc++.h>
using namespace std;

class StringIterator {
public:

    int count, i, n;
    string compressedString;
    char curr;

    StringIterator(string compressedString) {
        n = compressedString.size();
        i = 0;
        count = 0;
        this->compressedString = compressedString;
    }

    char next() {
        if (count == 0) {
            if (i >= n) return ' ';

            curr = compressedString[i++];
            while (i < n && isdigit(compressedString[i])) {
                count = count * 10 + (compressedString[i++] - '0');
            }
        }
        --count;
        return curr;
    }

    bool hasNext() {
        return i < n || count > 0;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */