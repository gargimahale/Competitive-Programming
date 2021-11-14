#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
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
        wireB.push_back({s.at(0), stoi(s.substr(1)});
    }

    set<pair<int, int> > visited;
    unordered_map<char, pair<int, int>> dirs = {{'R', {1,0}}, 
                                     {'L', {-1,0}}, 
                                     {'U', {0,1}}, 
                                     {'D', {0,-1}}};

    int x = 0, y = 0;

    for (pair<char, int> p : wireA){
        pair<int, int> d = dirs[p.first];
        for (int i = p.second; i > 0; i-- ){
            x += d.first;
            y += d.second;
            visited.insert({x, y});
        }
    } 

    int minIntersection = INT_MAX;
    x = 0, y = 0;

    for (pair<char, int> p : wireB){
        pair<int, int> d = dirs[p.first];
        for (int i = p.second; i > 0; i--){
            x += d.first;
            y += d.second;

            pair<int, int> p = {x, y};
            if (visited.find(p) != visited.end()){
                minIntersection = min(minIntersection, abs(x) + abs(y));
            }
        }
    }

    cout << minIntersection << "\n";
    return 0;
}