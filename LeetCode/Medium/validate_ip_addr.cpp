#include<bits/stdc++.h>

using namespace std;

// Can also be solved by re in c++ (new)!!

string solve(string IP) {
    long long i;
    unordered_map <char, long long> U, check;
    for(i=0;i<IP.length();i++){
        if(IP[i] == '.') U['.']++;
        if (IP[i] == ':') U[':']++;
    }
    string seg;
    bool present=true;
    stringstream S(IP);
    vector <string> i4, i6;
    if (U['.'] == 3 && IP.length() >= 7 && IP.length() <= 15){
        while(getline(S, seg, '.')) i4.push_back(seg);
        for(string a: i4){
            string c = a;
            int cnt=0;
            for(int k=0;k<c.length();k++) cnt++;
            if (cnt>3) return "Neither";
            if (c != "" && all_of(a.begin(), a.end(), ::isdigit) && stoi(c) <= 255){
                present = a.at(0) == '0';
                if (cnt == 1 && a == "0") continue;
                if (present == false) continue;
                else return "Neither";
            }
            else return "Neither";
        }
        if(present == false) return "IPv4";
        else return "Neither";
    }
    else if(U[':'] == 7){
        while(getline(S, seg, ':')) i6.push_back(seg);
        for(string a: i6){
            long long cnt=0;
            for(long long j=0;j<a.length();j++){
                if (isxdigit(a[j])) cnt++;
                else return "Neither";
            }
            if(cnt == 1 && a.at(0) == '0'){
                present = true;
                if(present) continue;
            }
            else if (cnt >=1 && cnt <=4) continue;
            else return "Neither";
        }
        return "IPv6";
    }
    else return "Neither";
}

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