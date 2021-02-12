#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int m,n;
    bool crushable(vector<vector<int>>& board){
        bool adjacent = false;
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i>=2 && board[i][j] != 0 && abs(board[i][j]) == abs(board[i-1][j]) && abs(board[i][j])==abs(board[i-2][j])){
                    board[i][j] = -abs(board[i-1][j]);
                    board[i-1][j] = board[i][j];
                    board[i-2][j] = board[i][j];
                    adjacent = true;
                }
                if(j>=2 && board[i][j]!=0 && abs(board[i][j])==abs(board[i][j-1]) && abs(board[i][j])==abs(board[i][j-2])){
                    board[i][j] = -abs(board[i][j-1]);
                    board[i][j-1] = board[i][j];
                    board[i][j-2] = board[i][j];
                    adjacent = true;
                }
            }
        }
        return adjacent;
    }

    void crush(vector<vector<int>>& board){
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(board[i][j]<0) board[i][j] = 0;
            }
        }
    }

    void drop(vector<vector<int>>& board){
        for(int j=0; j < n; j++){
            int iterator = m-1;
            for(int i=m-1; i>=0; i--){
                if(board[i][j]!=0){
                    board[iterator][j]=board[i][j];
                    iterator--;
                }
            }
            while(iterator>=0){
                board[iterator][j]=0;
                iterator--;
            }
        }
    }

    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        m = board.size();
        n = board[0].size();

        while(crushable(board)){
            crush(board);
            drop(board);
        }
        return board;
    }
};