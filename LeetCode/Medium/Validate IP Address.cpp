#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool validIPv4(string IP){
        if (count(IP.begin(), IP.end(), '.') != 3){
            return false;
        }
        
        vector<string> parts = split(IP, '.');
        if (parts.size() != 4){
            return false;
        }
        
        for (string part: parts){
            if (part.empty() || part.size() > 3 || part.size() > 1 && part[0] == '0'){
                return false;
            }
            for (char ch: part){
                if (!isdigit(ch)){
                    return false;
                }
            }
            if (stoi(part) > 255){
                return false;
            }
        }
        return true;
    }
    
    bool validIPv6(string IP){
        if (count(IP.begin(), IP.end(), ':') != 7){
            return false;
        }
        vector<string> parts = split(IP, ':');
        if (parts.size() != 8){
            return false;
        }
        
        for (string part: parts){
            if (part.empty() || part.size() > 4){
                return false;
            }
            for (char c: part){
                if (!isdigit(c) && (!isalpha(c) || toupper(c) > 'F')){
                    return false;
                }
            }
        }
        return true;
    }
    
    vector<string> split(string IP, char c){
        vector<string> parts;
        string part;
        istringstream iss(IP);
        while(getline(iss, part, c)){
            parts.push_back(part);
        }
        return parts;
    }
    
public:
    string validIPAddress(string IP) {
        return validIPv4(IP) ? "IPv4" : (validIPv6(IP) ? "IPv6": "Neither");
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    string s;
    cin >> s;
    while(t--) {
      cout << solve(s);
    }
    return 0;
}