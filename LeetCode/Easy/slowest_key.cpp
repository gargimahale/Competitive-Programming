#include <bits/stdc++.h>

using namespace std;

char slowestKey(vector<int>& releaseTimes, string keysPressed) {
    int time = releaseTimes[0], key =  keysPressed[0];
    for (int i = 1; i < keysPressed.size(); ++i) {
        if (releaseTimes[i] - releaseTimes[i - 1] > time) {
            time = releaseTimes[i] - releaseTimes[i - 1];
            key = keysPressed[i];
        }
        else if (releaseTimes[i] - releaseTimes[i - 1] >= time) {
            if (keysPressed[i] > keysPressed[i - 1]) {
                key = keysPressed[i];
            }
        }
    }
    return key;
}

int main() {
    vector<int> releaseTimes = {9, 29, 49, 50};
    string keysPressed = "cbcd";
    cout << slowestKey(releaseTimes, keysPressed);
    return 0;
}