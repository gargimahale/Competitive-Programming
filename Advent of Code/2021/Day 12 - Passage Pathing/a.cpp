#include <bits/stdc++.h>
using namespace std;

 void getPossiblePaths(unordered_set<string> &possible_paths,
                       string origin,
                       const unordered_map<string, vector<string>> &adj_map,
                       bool repeat_small_cave,
                       unordered_set<string> forbidden = {"start"},
                       string curr_path = ""){
    if (curr_path.size())
        curr_path.push_back(',');
    curr_path += origin;

    unordered_set<string> forbidden_without_origin(forbidden);
    bool origin_small_cave = false;
    if (islower(origin[0]) && origin != "start"){
        forbidden.insert(origin);
        origin_small_cave = true;
    }

    if (adj_map.find(origin) != adj_map.end()){
        for (const string &destination : adj_map.find(origin)->second){
            if (forbidden.find(destination) != forbidden.end())
                continue;

            if (destination == "end" && possible_paths.find(curr_path) == possible_paths.end()){
                possible_paths.insert(curr_path);
            }
            else if (repeat_small_cave && origin_small_cave){
                getPossiblePaths(possible_paths, destination, adj_map, true, forbidden, curr_path);
                getPossiblePaths(possible_paths, destination, adj_map, false, forbidden_without_origin, curr_path);
            }
            else
                getPossiblePaths(possible_paths, destination, adj_map, repeat_small_cave, forbidden, curr_path);
        }
    }
}

int main(void){
    ifstream input("input.txt");

    string line;
    string begining, end;

    unordered_map<string, vector<string>> adj_map;

    while (getline(input, line)){
        begining = line.substr(0, line.find("-"));
        end = line.substr(line.find("-") + 1, line.size());

        adj_map[begining].push_back(end);
        if (begining != "start" || end != "end")
            adj_map[end].push_back(begining);
    }

    input.close();

    unordered_set<string> paths = {};

    getPossiblePaths(paths, "start", adj_map, false);
    cout << "Part 1:\t" << paths.size() << "\n";

    paths = {};
    getPossiblePaths(paths, "start", adj_map, true);
    cout << "Part 2:\t" << paths.size() << "\n";
}