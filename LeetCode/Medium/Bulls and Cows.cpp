#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int secret_freq[10] = {0}, guess_freq[10] = {0};
        int bulls = 0, cows = 0;

        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) {
                ++bulls;
            }
            else {
                secret_freq[secret[i] - '0']++;
                guess_freq[guess[i] - '0']++;
            }
        }

        for (int i = 0; i < 10; ++i) {
            cows += min(secret_freq[i], guess_freq[i]);
        }

        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};