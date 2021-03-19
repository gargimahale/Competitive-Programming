#include<bits/stdc++.h>

using namespace std;

vector<string> sortFeatures(vector<string> &features, vector<string> &responses){
    unordered_map<string, int> mp;
    for (string str : responses){
        stringstream ss(str);
        string word;
        set<string> S;
        while (ss >> word) S.insert(word);
        for (auto it = S.begin(); it != S.end(); ++it)
            mp[*it]++;
    }
    
    unordered_map<string, int> idx;
    for (int i = 0; i < features.size(); ++i)
        idx[features[i]] = i;

    sort(begin(features), end(features), [&](auto a, auto b) {
        return mp[a] > mp[b] || (mp[a] == mp[b] && idx[a] < idx[b]);
    });
    return features;
}

int main() {
    vector<string> features = {"cooler","lock","touch"};
    vector<string> responses = {"i like cooler cooler", "lock touch cool", "locker like touch"};
    vector<string> res = sortFeatures(features, responses);
    for (string s: res) cout << s << " ";
    return 0;
}