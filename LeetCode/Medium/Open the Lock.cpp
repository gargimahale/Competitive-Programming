#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendSet (begin(deadends), end(deadends));
        unordered_set<string> visited;
        int result = 0;

        if (deadendSet.find("0000") != deadendSet.end()) {
            return -1;
        }

        queue<string> wheelQueue;
        wheelQueue.push("0000");
        visited.insert("0000");

        while (!wheelQueue.empty()) {
            int levelSize = wheelQueue.size();
            while (levelSize--) {
                string up, down, currentWheel = wheelQueue.front();
                wheelQueue.pop();
                if (currentWheel == target) {
                    return result;
                }

                for (int i = 0; i < 4; ++i) {
                    down = up = currentWheel;
                    char upCh = up[i], downCh = down[i];
                    up[i] = (upCh == '9' ? '0' : upCh + 1);
                    down[i] = (downCh == '0' ? '9' : downCh - 1);
                    if (visited.find(up) == visited.end() && deadendSet.find(up) == deadendSet.end()) {
                        wheelQueue.push(up);
                        visited.insert(up);
                    }
                    if (visited.find(down) == visited.end() && deadendSet.find(down) == deadendSet.end()) {
                        wheelQueue.push(down);
                        visited.insert(down);
                    }
                }
            }
            ++result;
        }

        return -1;
    }
};