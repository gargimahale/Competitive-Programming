#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isRobotBounded(string instructions) {
		int x = 0, y = 0;
		char dir = 'N';
		for (char ch : instructions) {
			if (ch == 'G') {
				if (dir == 'N') {
					++y;
				}
				else if (dir == 'W') {
					--x;
				}
				else if (dir == 'S') {
					--y;
				}
				else {
					++x;
				}
			}
			else if (ch == 'L') {
				if (dir == 'N') {
					dir = 'W';
				}
				else if (dir == 'W') {
					dir = 'S';
				}
				else if (dir == 'E') {
					dir = 'N';
				}
				else {
					dir = 'E';
				}
			}
			else {
				if (dir == 'N') {
					dir = 'E';
				}
				else if (dir == 'E') {
					dir = 'S';
				}
				else if (dir == 'W') {
					dir = 'N';
				}
				else {
					dir = 'W';
				}
			}
		}
		return (x == 0 && y == 0) || (dir != 'N');
	}
};