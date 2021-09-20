#include <bits/stdc++.h>
using namespace std;

/*

'4' in row 7 is encoded as "(4)7".
'4' in column 7 is encoded as "7(4)".
'4' in the top-right block is encoded as "0(4)2".

 */


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> seen;
        for (int i = 0; i<9; ++i){
            for (int j = 0; j<9; ++j){
                if (board[i][j] != '.'){
                    string temp = "(" + to_string(board[i][j]) + ")";
                    if (!seen.insert(temp+to_string(i)).second || !seen.insert(to_string(j)+temp).second || !seen.insert(to_string(i/3)+temp+to_string(j/3)).second){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};