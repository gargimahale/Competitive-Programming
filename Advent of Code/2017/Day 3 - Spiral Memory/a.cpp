#include <bits/stdc++.h>
using namespace std;

using position = pair<int, int>;

class walker {
    int side_length = 1;
    int move_direction = 3;
    int steps_to_go = 0;
public:
    void move(position& p) {
        if (steps_to_go == 0) {
            move_direction = (move_direction + 1) % 4;
            if (move_direction == 0) {
                ++p.second;
                side_length += 2;
                steps_to_go = side_length - 2;
                return;
            } else {
                steps_to_go = side_length - 1;
            }
        }
        switch (move_direction) {
            case 0: --p.first; break; // UP
            case 1: --p.second; break; // LEFT
            case 2: ++p.first; break; // DOWN
            case 3: ++p.second; break; // RIGHT
        }
        --steps_to_go;
    }
};

int main(void) {
    int n = 265149;
    position p{0, 0};

    walker w;
    int count = 1;
    while (count < n) {
        ++count;
        w.move(p);
    }
    cout << "Part 1: " << abs(p.first) + abs(p.second) << "\n";

    p = {0, 0};
    map<position, int> board;
    board[p] = 1;

    walker w1;
    while (board[p] <= n) {
        w1.move(p);
        board[p] =
            board[{p.first - 1, p.second - 1}] + board[{p.first - 1, p.second}] + board[{p.first - 1, p.second + 1}] +
            board[{p.first, p.second - 1}] + board[{p.first, p.second + 1}] +
            board[{p.first + 1, p.second - 1}] + board[{p.first + 1, p.second}] + board[{p.first + 1, p.second + 1}];
    }
    cout << "Part 2: " << board[p] << "\n";
}