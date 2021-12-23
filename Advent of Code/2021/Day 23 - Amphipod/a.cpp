#include <bits/stdc++.h>
using namespace std;

int Evaluate(const string& startState, const string& target){
    constexpr array<int, 7> validTopPos{ 0, 1, 3, 5, 7, 9, 10 };
    constexpr array<int, 4> roomsIndex = { 2, 4, 6, 8 }, typeCosts = { 1, 10, 100, 1000 };
    using CostState = pair<int, string>;
    unordered_set<string> evaluatedStates;
    priority_queue<CostState, vector<CostState>, greater<CostState>> toEvaluate;

    auto MoveToRoom = [&roomsIndex, &typeCosts](const string& state, int pos) -> CostState{
        char type = state[pos];
        int target = roomsIndex[type - 'A'], work = pos, cost = 0;
        
        do{
            work += (pos > target) ? -1 : 1;
            ++cost;
            if (state[work] != '.')
                return { 0, "" };
        } while (work != target);
        
        for (int i = work; i < state.size(); i += 11)
            if (state[i] != '.' && state[i] != type)
                return { 0, "" };

        while (work + 11 < state.size() && state[work + 11] == '.'){
            work += 11;
            ++cost;
        }

        string newState = state;
        swap(newState[pos], newState[work]);
        return { typeCosts[type - 'A'] * cost, newState };
    };

    auto MoveFromRoomTo = [&typeCosts](const string& state, int from, int to) -> CostState{
        char type = state[from];
        int cost = 0, work = from;
        
        while (work > 10){
            work -= 11;
            ++cost;
            if (state[work] != '.')
                return { 0, "" };
        }

        while (work != to){
            work += (work < to ? 1 : -1);
            ++cost;
            if (state[work] != '.')
                return { 0, "" };
        }

        string newState = state;
        swap(newState[from], newState[to]);
        return { typeCosts[type - 'A'] * cost, newState };
    };

    toEvaluate.push({ 0, startState });

    while (!toEvaluate.empty()){
        const CostState cs = toEvaluate.top();
        const int baseCost = cs.first;
        const string& baseState = cs.second;
        toEvaluate.pop();
        
        if (cs.second == target)
            return baseCost;

        if (auto [_, s] = evaluatedStates.insert(baseState);
            !s)
            continue;

        for (int pos : validTopPos)
            if (baseState[pos] != '.')
                if (auto [cost, newState] = MoveToRoom(baseState, pos);
                    cost > 0)
                    toEvaluate.push({ cost + baseCost, newState });

        int work = 11;
        while (work < baseState.size()){
            for (int delta : roomsIndex)
                if (baseState[work + delta] != '.')
                    for (int targetPos : validTopPos)
                        if (auto [cost, newState] = MoveFromRoomTo(baseState, work + delta, targetPos);
                            cost > 0)
                            toEvaluate.push({ cost + baseCost, newState });
            work += 11;
        }
    }
    return -1;
}

int main(void){
    ifstream in("input.txt");

    string s, target = "...........##A#B#C#D## #A#B#C#D#";

    in >> s >> s;
    string startState = s.substr(1, s.size() - 2);
    in >> s;
    startState += s.substr(1, s.size() - 2);
    in >> s;
    startState += ' ' + s;        

    cout << "Part 1: " << Evaluate(startState, target);

    string newStartState = startState.substr(0, 22) + " #D#C#B#A#  #D#B#A#C# " + startState.substr(22);
    target += "  #A#B#C#D#  #A#B#C#D#";
    cout << "\nPart 2: " << Evaluate(newStartState, target) << endl;
    return 0;
}