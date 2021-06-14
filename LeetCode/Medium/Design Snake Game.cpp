#include <bits/stdc++.h>
using namespace std;

class SnakeGame {
    int w, h;
    vector<vector<int>> food;
    int foodPos;
    deque<pair<int, int>> snake;
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        w = width;
        h = height;
        foodPos = 0;
        this->food = food;
        snake.push_front(make_pair(0, 0));
    }

    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down
        @return The game's score after the move. Return -1 if game over.
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        int row = snake.front().first;
        int col = snake.front().second;
        if (direction == "U") --row;
        else if (direction == "L")  --col;
        else if (direction == "R")  ++col;
        else if (direction == "D")  ++row;

        //hits boundary
        if (row < 0 || row >= h || col < 0 || col >= w) return -1;
        //bites it's body
        pair<int, int>temp = make_pair(row, col);
        if (find(snake.begin(), snake.end(), temp) != snake.end()) {
            //if it's the last place no collision
            if (temp != snake.back()) return -1;
        }
        if (foodPos < food.size() && row == food[foodPos][0] && col == food[foodPos][1]) {
            foodPos++;
        } else
            snake.pop_back();
        snake.push_front(temp);
        return foodPos;
    }
};


// TC: O(1)
// SC: O(W*H + N)