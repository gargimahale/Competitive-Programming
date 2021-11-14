#include <bits/stdc++.h>
using namespace std;

int main(void){
    freopen("input.txt", "r", stdin);

    string inputA, inputB;
    getline(cin, inputA);
    getline(cin, inputB);

    stringstream ssA, ssB;
    ssA << inputA;
    ssB << inputB;

    vector<pair<char, int>> wireA, wireB;
    string s;

    while (getline(ssA, s, ',')){
        wireA.push_back({s.at(0), stoi(s.substr(1))});
    }

    while (getline(ssB, s, ',')){
        wireB.push_back({s.at(0), stoi(s.substr(1))});
    }

    map<pair<int, int>, long> visited;
    map<char, pair<int, int>> dirs = {{'R', {1,0}}, 
                                     {'L', {-1,0}}, 
                                     {'U', {0,1}}, 
                                     {'D', {0,-1}}};

    int x = 0, y = 0;
    long steps = 0;

    for (pair<char, int> p : wireA){
        pair<int, int> d = dirs[p.first];
        for (int i = p.second; i > 0; --i){
            x += d.first;
            y += d.second;
            visited.insert({{x, y}, ++steps});
        }
    } 

    long minIntersection = LONG_MAX;
    x = 0, y = 0, steps = 0;

    for (pair<char, int> p : wireB){
        pair<int, int> d = dirs[p.first];
        for (int i = p.second; i > 0; --i){
            x += d.first;
            y += d.second;
            ++steps;

            pair<int, int> p = {x, y};
            if (visited.find(p) != visited.end()){
                minIntersection = min(minIntersection, (*visited.find(p)).second + steps);
            }
        }
    }

    cout << minIntersection << "\n";
    return 0;
}