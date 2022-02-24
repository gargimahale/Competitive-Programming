#include <bits/stdc++.h>
using namespace std;

/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    void cleanRoomRecursive(Robot &robot, unordered_set<string> &visited, const vector<vector<int>>& directions, int i, int j, int faceDirection) {
        visited.insert(to_string(i) + "," + to_string(j));
        robot.clean();
        for (int k = 0; k < 4; ++k) {
            int nextFaceDirection = (faceDirection + k) % 4;
            int iNext = i + directions[nextFaceDirection][0];
            int jNext = j + directions[nextFaceDirection][1];
            if (!visited.count(to_string(iNext) + "," + to_string(jNext)) && robot.move()) {
                cleanRoomRecursive(robot, visited, directions, iNext, jNext, nextFaceDirection);
                robot.turnRight();
                robot.turnRight();
                robot.move();
                robot.turnRight();
                robot.turnRight();
            }
            robot.turnRight();
        }
    }

    void cleanRoom(Robot& robot) {
        vector<vector<int>> directions = {{ -1, 0}, {0, 1}, {1, 0}, {0, -1}};
        unordered_set<string> visited;
        cleanRoomRecursive(robot, visited, directions, 0, 0, 0);
    }
};
