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
            ++idx;

            while(idx < range.size()){
                res[1] = res[1]*10 + (range[idx++]-'0');
            }
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
        
        int count = 0;
        for (int i = 0; i < word.size(); ++i){
            count += (word[i] == test);
        }

        if (count >= r[0] && count <= r[1]){
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