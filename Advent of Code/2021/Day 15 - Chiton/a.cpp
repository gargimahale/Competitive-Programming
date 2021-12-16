#include <bits/stdc++.h>
using namespace std;

#define WIDTH 100
#define HEIGHT 100
#define INF 0x3f3f3f3f

struct coord{
    int x, y;
};

using coord_set = unordered_set<coord>;

template <>
struct hash<coord>{
    size_t operator()(const coord &c) const {
        return c.x | (uint64_t) c.y << 32;
    }
};

struct coord_pr{
    int pr;
    coord c;
};

template <> 
struct greater<coord_pr>{
    bool operator()(const coord_pr &lhs, const coord_pr &rhs) const{
        return lhs.pr > rhs.pr;
    }
};

int dijkstra(int grid[HEIGHT][WIDTH]){
    priority_queue<coord_pr, vector<coord_pr>, greater<coord_pr>> q;

    int dists[HEIGHT][WIDTH];
    for (int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){
            dists[y][x] = INF;
        }
    }

    vector<coord> neighbours = {
        { -1,  0 },
        {  1,  0 },
        {  0, -1 },
        {  0,  1 }
    };

    q.push({ 0, { 0, 0 } });
    dists[0][0] = 0;

    while (!q.empty()){
        auto c = q.top().c;
        q.pop();

        for (auto neighbour : neighbours){
            if (c.x + neighbour.x < 0
                || c.x + neighbour.x >= HEIGHT
                || c.y + neighbour.y < 0
                || c.y + neighbour.y >= WIDTH){
                continue;
            }

            int &from = dists[c.y][c.x];
            int &to = dists[c.y + neighbour.y][c.x + neighbour.x];
            int cost = grid[c.y + neighbour.y][c.x + neighbour.x];

            if (to > from + cost){
                to = from + cost;
                q.push({ to, { c.x + neighbour.x, c.y + neighbour.y } });
            }
        }
    }
    return dists[HEIGHT - 1][WIDTH - 1];
}

int main(void){
    string s;
    int grid[HEIGHT][WIDTH];
    ifstream myFile("input.txt");

    for (int y = 0; y < HEIGHT; y++){
        getline(myFile, s);
        for (int x = 0; x < WIDTH; x++){
            grid[y][x] = s[x] - '0';
        }
    }

    cout << dijkstra(grid) << "\n";
}