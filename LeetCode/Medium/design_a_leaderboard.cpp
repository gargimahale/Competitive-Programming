#include <bits/stdc++.h>

using namespace std;

class Leaderboard {
public:
    vector<pair<int, int>> players;

    Leaderboard() {}

    void addScore(int playerId, int score) {
        if (players.size() == 0){
            players.push_back(make_pair(playerId, score));
        }
        else{
            int i=0;
            while(i < players.size() && players[i].first != playerId){
                i++;
            }
            if (i < players.size()){
                players[i].second += score;
            }
            else{
                players.insert(players.begin(), make_pair(playerId, score));
                // players.pb(make_pair(playerId, score));
                i = 0;
            }
            while(i+1 < players.size() && players[i].second > players[i+1].second){
                swap(players[i], players[i+1]);
                i++;
            }
        }
    }

    int top(int K) {
        int sum = 0;
        for (int i=players.size()-1; i>= players.size()-K; --i){
            sum+=players[i].second;
        }
        return sum;
    }

    void reset(int playerId) {
        int idx;
        for (idx = 0; players[idx].first != playerId; ++idx){}
        players.erase(players.begin()+idx);
    }
};