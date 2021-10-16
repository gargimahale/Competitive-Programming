#import <bits/stdc++.h>
using namespace std;

// https://leetcode.com/discuss/interview-question/776648/dynamic-programming-question
// https://cs.stanford.edu/people/eroberts/courses/soco/projects/computers-and-the-hgp/smith_waterman.html

vector<string> diffBetweenTwoStrings(const string& source, const string& target){

    vector<string> ans;
    int n = source.size(), m = target.size();
    vector<vector<int>> dp(n+1, vector<int> (m+1));

    for (int i = 0; i <= n; ++i){
        dp[i][m] = n - i;
    }

    for (int j = 0; j <= m; ++j){
        dp[n][j] = m - j;
    }

    for (int i = n-1; i >= 0; --i){
        for (int j = m-1; j >= 0; --j){
            if (source[i] == target[j]){
                dp[i][j] = 1 + dp[i+1][j+1];
            }
            else{
                dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    int i = 0, j = 0;
    while(ans.size() != dp[0][0]){
        if (i >= n){
            string temp = "+";
            temp.push_back(target[j]);
            ++j;
            ans.push_back(temp);
            continue;
        }

        if (j >= m){
            string temp = "-";
            temp.push_back(source[i]);
            ++i;
            ans.push_back(temp);
            continue;
        }

        if (source[i] == target[j]){
            string temp = "";
            temp = temp + source[i];
            ans.push_back(temp);
            ++i, ++j;
        }
        else{
            if (dp[i+1][j] <= dp[i][j+1]){
            string temp = "-";
            temp.push_back(source[i]);
            ans.push_back(temp);
            i++;
            }
            else{
                string temp = "+";
                temp.push_back(target[j]);
                ans.push_back(temp);
                j++;
            }
        }
    }
    return ans;
}

int main(){
    string source = "ABCDEFG", target = "ABDFFGH";
    vector<string> ans = diffBetweenTwoStrings(source, target);
    for (string& str: ans){
        cout << str << "\n";
    }
    return 0;
}