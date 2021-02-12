#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    unordered_map<char,int> m;

    int findMinStep(string board, string hand) {
        if(board.size()==0) return 0;
        vector<int> handcnt(5,0);
        for(auto& h:hand){
            if(h=='R') handcnt[0]++;
            else if(h=='Y') handcnt[1]++;
            else if(h=='B') handcnt[2]++;
            else if(h=='G') handcnt[3]++;
            else if(h=='W') handcnt[4]++;
        }
        m['R']=0;
        m['Y']=1;
        m['B']=2;
        m['G']=3;
        m['W']=4;

        auto res=dfs(board,handcnt,0);

        return res==(INT_MAX>>1)?-1:res;
    }

    int dfs(const string& board, const vector<int>& hand,int idx){
        if(idx==board.size()) return 0;


        int res=(INT_MAX>>1);
        //insert on the left
        for(int i=idx;i<board.size();++i){
            if(i==0||board[i]!=board[i-1]){
                int cnt=0,j=i;
                while(j<board.size()&&board[j]==board[i])cnt++,j++;
                int need=3-cnt;
                if(need<0) need=0;
                if(hand[m[board[i]]]<need) continue;

                vector<int> newhand(hand);
                newhand[m[board[i]]]-=need;
                string newboard=board.substr(0,i)+board.substr(j);

                res=min(res,need+dfs(newboard,newhand,0));
                //cout<<res<<","<<newboard<<"!"<<board<<endl;
            }
        }

        return res;
    }
};