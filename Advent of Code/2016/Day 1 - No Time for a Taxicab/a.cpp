#include <bits/stdc++.h>
using namespace std;

struct Dir {
    int dx{0}, dy{1};
    void rotate(int turn) {
        swap(dx, dy);
        if (turn < 0) {
        	dx *= -1;
        } 
        else {
        	dy *= -1;
        }
    }
};

struct Pos {
    int x{0}, y{0};

    void forward(const Dir& d, int len) { 
    	x += len * d.dx; 
    	y += len * d.dy; 
    }
};

int main() {
    Dir d;
    Pos p;        
    string line = "R4, R4, L1, R3, L5, R2, R5, R1, L4, R3, L5, R2, L3, L4, L3, R1, R5, R1, L3, L1, R3, L1, R2, R2, L2, R5, L3, L4, R4, R4, R2, L4, L1, R5, L1, L4, R4, L1, R1, L2, R5, L2, L3, R2, R1, L194, R2, L4, R49, R1, R3, L5, L4, L1, R4, R2, R1, L5, R3, L5, L4, R4, R4, L2, L3, R78, L5, R4, R191, R4, R3, R1, L2, R1, R3, L1, R3, R4, R2, L2, R1, R4, L5, R2, L2, L4, L2, R1, R2, L3, R5, R2, L3, L3, R3, L1, L1, R5, L4, L4, L2, R5, R1, R4, L3, L5, L4, R5, L4, R5, R4, L3, L2, L5, R4, R3, L3, R1, L5, R5, R1, L3, R2, L5, R5, L3, R1, R4, L5, R4, R2, R3, L4, L5, R3, R4, L5, L5, R4, L4, L4, R1, R5, R3, L1, L4, L3, L4, R1, L5, L1, R2, R2, R4, R4, L5, R4, R1, L1, L1, L3, L5, L2, R4, L3, L5, L4, L1, R3";
    const regex re("([RL])(\\d+)");
    for (sregex_iterator m{line.begin(), line.end(), re}; m != sregex_iterator(); ++m) {
        d.rotate(((*m)[1] == "L") ? -1 : +1);
        p.forward(d, stoi((*m)[2]));
    }
    cout << (abs(p.x) + abs(p.y)) << endl;
    return 0;
}