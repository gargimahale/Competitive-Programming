#include <bits/stdc++.h>
using namespace std;

void column_rotate(vector<vector<int>>& screen, int column, int amount);

int main(void){
    ifstream fin("input.txt");
    string line;
    vector<vector<int>> screen(6, vector<int>(50, 0));
    while (getline(fin, line)){
        string command, row_or_column;
        int row_or_column_number, value;
        stringstream ss(line);
        ss >> command;
        if (command == "rect"){
            int x, y;
            char eater;
            ss >> x >> eater >> y;
            for (int i = 0; i < y; ++i)
                for (int j = 0; j < x; ++j)
                    screen[i][j] = 1;
        }
        else{
            char eater;
            ss >> row_or_column >> eater >> eater >> row_or_column_number >> eater >> eater >> value;
            if (row_or_column == "row"){
                auto& row = screen[row_or_column_number];
                rotate(row.rbegin(), row.rbegin() + value, row.rend());
            }
            else{
                column_rotate(screen, row_or_column_number, value);
            }
        }
    }
    
    // Part 1
    int counter = 0;
    for (int i = 0; i < 6; ++i)
        for (int j = 0; j < 50; ++j)
            if (screen[i][j] == 1)
                counter++;
    cout << "Part 1: " << counter << "\n";

    // Part 2
    counter = 0;
    for (int i = 0; i < 6; ++i){
        for (int j = 0; j < 50; ++j){
            if (j && j % 5 == 0)
                cout << " ";
            cout << (screen[i][j] ? 'X' : ' ');
        }
        cout << "\n";
    }
}

void column_rotate(vector<vector<int>>& screen, int column, int amount){
    vector<int> col;
    for (int i = 0; i < 6; i++)
        col.push_back(screen[i][column]);
    rotate(col.rbegin(), col.rbegin() + amount, col.rend());
    for (int i = 0; i < 6; i++)
        screen[i][column] = col[i];
}