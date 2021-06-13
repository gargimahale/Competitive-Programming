#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {

        unordered_set<string> cnt;
        bool foundAT = false;
        int n = emails.size();

        for (int i = 0; i < n; ++i) {
            string temp = "";
            foundAT = false;
            int j = 0;
            while (j < emails[i].size()) {


                if (emails[i][j] == '.' && foundAT == false) ++j;


                else if (emails[i][j] == '+') {
                    while (j < emails[i].size() && emails[i][j] != '@') ++j;
                    temp += emails[i][j++];
                    foundAT = true;
                }


                else {
                    if (emails[i][j] == '@') {
                        foundAT = true;
                    }
                    temp += emails[i][j++];
                }
            }


            if (!cnt.count(temp)) {
                cnt.insert(temp);
            }
        }

        return cnt.size();
    }
};

// TC: O(N*M)
// SC: O(N)