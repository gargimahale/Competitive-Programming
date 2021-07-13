#include <bits/stdc++.h>
using namespace std;

class MyCalendar {
public:
    set<pair<int, int>> books;

    MyCalendar() {}

    bool book(int start, int end) {
        auto it = books.lower_bound({start, end});

        if (it != books.end() && it->first < end) return false;
        if (it != books.begin() && (--it)->second > start) return false;

        books.emplace(start, end);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
