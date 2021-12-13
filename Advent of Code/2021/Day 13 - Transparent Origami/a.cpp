#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> yFold(vector<vector<string>> paper, int fold){
    int c = 2;
    for(int row = fold - 1; row >= 0; row--, c+=2){
        for(int col = 0; col < paper[0].size(); col++){
            string p = paper[row + c][col];
            if(p == ".") continue;
            else{
                paper[row][col] = p;
            }
        }
    }

    vector<vector<string>> newPaper;
    for(int i = 0; i < fold; i++){
        newPaper.push_back(paper[i]);
    }
    return newPaper;
}

vector<vector<string>> xFold(vector<vector<string>> paper, int fold){
    int c = 2;
    for(int col = fold - 1; col >= 0; col--, c+=2){
        for(int row = 0; row < paper.size(); row++){
            string p = paper[row][col + c];
            if(p == ".") continue;
            else{
                paper[row][col] = p;
            }
        }
    }

    vector<vector<string>> newPaper;
    for(int i = 0; i < paper.size(); i++){
        vector<string> f(paper[i].begin(), paper[i].begin() + fold);
        newPaper.push_back(f);
    }
    return newPaper;
}

void part1(vector<vector<string>> paper, tuple<string, int> fold){
    string foldType = get<0>(fold);
    int foldNum = get<1>(fold);
    if(foldType == "x"){
        paper = xFold(paper, foldNum);
    }
    else{
        paper = yFold(paper, foldNum);
    }

    int answer1 = 0;
    for(int i = 0; i < paper.size(); i++){
        answer1 += count_if(paper[i].begin(), paper[i].end(), [](string x){return x == "#";});
    }
    cout << "Part 1 Answer : " << answer1 << "\n";
}

void part2(vector<vector<string>> paper, vector<tuple<string, int>> folds){
    
    for(auto fold : folds){
        string foldType = get<0>(fold);
        int foldNum = get<1>(fold);
        if(foldType == "x"){
            paper = xFold(paper, foldNum);
        }
        else{
            paper = yFold(paper, foldNum);
        }
    }

    for(int i = 0; i < paper.size(); i++){
        for(int j = 0; j < paper[0].size(); j++){
            cout << paper[i][j];
        }
        cout << "\n";
    }
}

int main(void){
    ifstream file("input.txt");
    vector<vector<string>> input(2000, vector<string> (2000, "."));
    vector<tuple<string, int>> folds;
    string line;

    while(getline(file, line)){
        if(line.find(",") != string::npos){
            int x = stoi(line.substr(0, line.find(",")));
            int y = stoi(line.substr(line.find(",")+1, string::npos));
            input[y][x] = "#";
        }

        else if(line.find("=") != string::npos){
            string fold = line.substr(line.find("=") - 1,string::npos);
            string foldType = fold.substr(0, fold.find("="));
            int foldNum = stoi(fold.substr(fold.find("=") + 1, string::npos));
            folds.push_back(make_tuple(foldType, foldNum));
        }
    }

    part1(input, folds[0]);
    part2(input, folds);
}