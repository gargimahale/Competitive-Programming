#include <bits/stdc++.h>
using namespace std;

int main(void) {
    vector<int> c;
    int w = 0;
    
    string line;
    ifstream myFile("input.txt");

    while (getline(myFile, line)) {

        if (c.empty()) { 
        	w = line.size(); 
        	c.assign(26 * w, 0); 
        }
        
        for (int i = 0; i < w; ++i) {
            c[26 * i + (line[i] - 'a')]++;
        }
    }

    line.resize(w);
    string text(begin(line), end(line));

    for (int i = 0; i < w; ++i) {
        int max_c = -1, min_c = -1;
        for (int j = 0; j < 26; ++j) {
            if (c[26 * i + j] > max_c) {
                max_c = c[26 * i + j];
                line[i] = 'a' + j;
            }

            if (c[26 * i + j] > 0 && (min_c < 0 || c[26 * i + j] < min_c)) {
                min_c = c[26 * i + j];
                text[i] = 'a' + j;
            }
        }
    }
    cout << "Part 1:" << line << endl;
    cout << "Part 2:" << text << endl;
}