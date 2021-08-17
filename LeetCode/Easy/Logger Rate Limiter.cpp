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
    unordered_set<string> temp_log;
    deque<pair<int, string>> message_log;
    Logger() {}
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        while(!message_log.empty() && message_log.front().first <= timestamp){
            temp_log.erase(message_log.front().second);
            message_log.pop_front();
        }
        
        if (temp_log.find(message) != temp_log.end()) return false;
        
        temp_log.insert(message);
        message_log.push_back({timestamp+10, message});
        return true;
    }
};

// TC: O(N)
// SC: O(N) where k is the #messages printed in last 10 sec

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