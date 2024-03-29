#include <bits/stdc++.h>
using namespace std;

class Player {
    public:
    int spot;
    int score = 0;
    Player(int spot) : spot(spot) {};
};

bool keepPlaying(vector<Player> players) {
    for (Player p : players) {
        if (p.score >= 1000) return false;
    }
    return true;
}

int roll(int &dice) {
    return ++dice;
}

int main(void) {
    ifstream input("input.txt");
    if (!input.good()) {
        cout << "Could not open file." << endl;
        return 2;
    }

    vector<Player> players;

    while (!input.eof()) {
        string line;
        getline(input, line);

        if (input.eof()) {
            break;
        }

        cout << line.substr(28) << endl;
        players.push_back(Player(stoi(line.substr(28))));
    }

    int dice = 0, i = 0;
    while (keepPlaying(players)) {
        int amountToMove = roll(dice) + roll(dice) + roll(dice);
        players[i].spot = (players[i].spot - 1 + amountToMove) % 10 + 1;
        players[i].score += players[i].spot;

        i = (i + 1) % players.size();
    }

    cout << "Number of rolls: " << dice << endl;
    cout << "Losing score: " << players[i].score << endl;
    cout << "Multiplied: " << dice * players[i].score << endl;
}