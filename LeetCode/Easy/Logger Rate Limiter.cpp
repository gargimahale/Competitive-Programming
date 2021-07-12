#include <bits/stdc++.h>
using namespace std;

class Logger {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> log;

    Logger() {}

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (timestamp < log[message]) return false;
        log[message] = timestamp + 10;
        return true;
    }
};


// OR

class Logger {
public:
    /** Initialize your data structure here. */
    unordered_set<string> S;
    deque<pair<int, string>> Q;


    Logger() {}

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        while (!Q.empty() && Q.front().first <= timestamp) {
            S.erase(Q.front().second);
            Q.pop_front();
        }

        if (S.count(message)) return false;

        Q.push_back({timestamp + 10, message});
        S.insert(message);

        return true;
    }
};

// TC: O(1), amortized
// SC: O(k) where k is the #messages printed in last 10 sec

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */

int main() {
    Logger s;
    for (int i = 0; i < 10; ++i) {
        int time;
        string message;
        cin >> time >> message;
        cout << s.shouldPrintMessage(time, message) << endl;
    }
    return 0;
}