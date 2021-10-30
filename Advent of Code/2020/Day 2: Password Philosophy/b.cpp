#include <bits/stdc++.h>
using namespace std;

class Solution{
    vector<int> getRange(string& range){
        int idx = 0;
        vector<int> res(2, 0);
        while(idx < range.size()){
            while(idx < range.size() && range[idx] != '-'){
                res[0] = res[0]*10 + (range[idx++]-'0');
            }
            res[0] -= 1;
            ++idx;

            while(idx < range.size()){
                res[1] = res[1]*10 + (range[idx++]-'0');
            }
            res[1] -= 1;
        }
        return res;
    }
public:
    void checkIfValid(istringstream& iss, int& res){
        string range, word, ch;
        char del = ' ';

        getline(iss, range, del);
        getline(iss, ch, del);
        getline(iss, word, del);

        vector<int> r = getRange(range);
        char test = ch[0];
        bool first = false, second = false;

        if (r[0] >= 0 && r[0] < word.size()){
            if (word[r[0]] == test){
                first = true;
            }
        } 

        if (r[1] >= 0 && r[1] < word.size()){
            if (word[r[1]] == test){
                second = true;
            }
        } 
        
        if (!first && second){
            ++res;
        }
        else if (first && !second){
            ++res;
        }
    }
};

int main(void) {
    Solution sol;
    ifstream myfile("input.txt");
    int res = 0;
    
    while (!myfile.eof()) {
        string text;
        getline(myfile, text);

        istringstream iss(text);

        sol.checkIfValid(iss, res);
    }
    cout << res << "\n";
}