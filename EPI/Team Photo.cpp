#include <bits/stdc++.h>
using namespace std;

struct Player {
    bool operator<(const Player& that) const {
        return height < that.height;
    }

    int height;
    Player(int _height): height(_height) {}
};

class Test {
public:
    bool isValidPlacement(vector<Player>& team1, vector<Player>& team2) const {
        // Assuming team size is >= 2 atleast

        sort(begin(team1), end(team1));
        sort(begin(team2), end(team2));

        for (int i = 0; i < team1.size() && i < team2.size(); ++i) {
            if (!(team1[i].height < team2[i].height)) {
                return false;
            }
        }

        return true;
    }
};

int main(void) {
    Test t;
    vector<Player> team1, team2;
    for (int i = 0; i <= 5; ++i) {
        int a, b;
        cin >> a >> b;
        Player p1(a);
        Player p2(b);
        team1.emplace_back(p1);
        team2.emplace_back(p2);
    }
    cout << t.isValidPlacement(team1, team2) << "\n";
}