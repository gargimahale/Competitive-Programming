#include <bits/stdc++.h>
using namespace std;

int sum_to(vector<int> containers, vector<int>& sizes, int goal, int values_in_goal = 0) {
    // if there are no number anymore return 0 combinations
    if (containers.size() == 0 )
        return 0;

    // split the array in two parts, the first value and the remain values
    int first = containers[0];
    vector<int> remain; remain.assign(containers.begin() + 1, containers.end());

    // keep track of the number of combinations that use the first value
    int with_first;
    if (first > goal)   // first value is larger then goals, do not use the first value (0 combinations)
        with_first = 0;
    else if ( first == goal ) { // if the first value is the goal, this is good. Store the number of values used and use the first value
        sizes.push_back(values_in_goal + 1);
        with_first = 1;
    } 
    else { // use the first value and recurse with the remaining values to a lower goal, increase the values in the goal combination
        with_first = sum_to(remain, sizes, goal - first, values_in_goal + 1);
    }

    // recurse on the rest of the array without using the first value
    // return the sum of the number of combination where the first number is used and where the first number is not used
    return with_first + sum_to(remain, sizes, goal, values_in_goal);
}

int main() {

    // array for the containers
    vector<int> containers;
    // array for the numbers of sizes used in the solution (required for Part 2)
    vector<int> sizes;

    // read the sizes of the containers from cin
    string line;
    ifstream myFile("input.txt");
    while (getline(myFile, line)) {
        containers.push_back(stoi(line));
    }

    // sort the containers (n.b. not necessary)
    sort(containers.begin(),containers.end());
    
    // call the recursive function and print the number of solutions
    cout << "Part 1: "  << sum_to(containers, sizes, 150) << "\n";

    // sort the sizes of the solutions
    sort(sizes.begin(),sizes.end());

    // find the minimum size
    int min = sizes[0];
    // count the number of sizes equal to the minimum
    int c = 0;
    for (auto s: sizes)
        if (min == s) ++c; else if (s > min) break;

    // print the number of solutions with the minimum number of containers used
    cout << "Part 2: " << c << "\n";
}