#include <bits/stdc++.h>

using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string encodedString = "";
        for(string s: strs){
            encodedString += to_string(s.length()) + "@" + s;
        }
        return encodedString;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> result;
        int idx = 0;
        while(idx < s.size()){
            int pos = s.find_first_of('@', idx);
            int len = stoi(s.substr(idx, pos-idx));
            idx = pos+1;
            result.push_back(s.substr(idx, len));
            idx += len;
        }
        return result;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));


// OR

// class Codec {
// public:

//     // Encodes a list of strings to a single string.
//     unordered_map<string, vector<string>> mp;
//     string encode(vector<string>& strs) {
//         string ans = "";
//         for (int i=0; i<strs.size(); ++i){
//             ans += strs[i];
//         }
//         mp[ans] = strs;
//         return ans;
//     }

//     // Decodes a single string to a list of strings.
//     vector<string> decode(string s) {
//         return mp[s];
//     }
// };

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));