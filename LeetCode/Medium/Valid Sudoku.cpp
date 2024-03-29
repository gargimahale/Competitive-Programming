#include <bits/stdc++.h>
#include <string>
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
        int rows = board.size(), cols = board[0].size();
        
        for (int i = 0; i < rows; ++i){
            for (int j = 0; j < cols; ++j){
                if (board[i][j] != '.'){
                    string temp = "(" + to_string(board[i][j]) + ")";
                    if (!seen.insert(temp + " in row " + to_string(i)).second || !seen.insert(temp + " in col " + to_string(j)).second || !seen.insert(temp + " in block " + to_string(i/3) + "-" + to_string(j/3)).second){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};