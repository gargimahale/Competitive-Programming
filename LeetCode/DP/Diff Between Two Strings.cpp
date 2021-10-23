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


#       ""    A    B    D    F    F    G     H
# ""   0     1    2     3    4    5    6     7
# A    1     0    1     2.   3.   4.   5.    6
# B    2     1.   0     1.   2.   3.   4.    5
# C    3     2.   1.    0.   2.   3.   4.    5
# D    4     3.   2.    1    2.   3.   4.    5
# E    5     4.   3.    2.   2.   3.   4.    5
# F    6     5.   4.    3.   3.   3.   4.    5
# G    7     6.   5.    4.   4.   4.   3.    4


# {"A",  "B", "-C", "D",  "-E", "F",  "+F",  "G", "H"}
def diffBetweenTwoStrings(source, target):
    ans = []
    rows, cols = len(target) + 1, len(source) + 1
    edits =[[x for x in range(cols)] for y in range(rows)]
            
    for i in range(1, len(target) + 1):
        edits[i][0] = edits[i-1][0] + 1
    
    for r in range(1, len(target) + 1):
        for c in range(1, len(source)+1):
            if target[r - 1] == source[c - 1]:
                edits[r][c] = edits[r-1][c-1]
            else:
                edits[r][c] = 1 + min(edits[r][c-1], edits[r-1][c])

    i, j = 0, 0
    while i < len(source) and j < len(target):
        if source[i] == target[j]:
            # Write the string with no edits
            ans.append(target[j])
            i += 1
            j += 1
        else:
            # We have to decide whether to subtract source[r], or add target[c].
            if edits[i+1][j] <= edits[i][j+1]:
                ans.append("-" + source[i])
                i+=1
            else:
                ans.append("+" + target[j])
                j+=1

    while j < len(target):
        ans.append('+' + target[j])
        j += 1

    return ans