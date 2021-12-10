#include <bits/stdc++.h>
using namespace std;

struct Program{
    string name;
    Program * parent = nullptr;
    vector<Program *> children;
    int weight;
    int totalWeight;

    int computeTotalWeightRecursive(){
        return totalWeight = weight + accumulate(children.begin(), children.end(), 0, [](int w, Program * child) { 
            return w + child->computeTotalWeightRecursive();
        });
    }

    pair<bool, int> isBalanced() const{
        if (children.size() >= 2){
            int first_child_weight = children[0]->totalWeight;
            int other_child_weight = 0;
            bool first_child_weight_confirmed = false;
            bool all_the_same = true;
            size_t other_child_index = 0;

            for (size_t i = 1; i < children.size(); ++i){
                if (!all_the_same && i > 2) break;

                if (children[i]->totalWeight == first_child_weight){
                    first_child_weight_confirmed = true;
                }
                else{
                    all_the_same = false;
                    other_child_index = i;
                    other_child_weight = children[i]->totalWeight;
                }
            }

            return make_pair(
                all_the_same,
                children[ first_child_weight_confirmed ? other_child_index : 0 ]->weight + ( first_child_weight - other_child_weight ) * ( first_child_weight_confirmed ? 1 : -1 )
            );
        }

        return make_pair(true, 0);
    }
};

int main(void){
    string line;
    map<string, unique_ptr<Program>> map;
    ifstream myFile("input.txt");
    while(getline(myFile, line)){
        char name[32];
        int weight;
        char children[256];
        memset(children, 0, sizeof( children));
        int scanned = sscanf(line.c_str(), "%s (%d) -> %[^\n]", name, &weight, children);

        auto insert = map.emplace(name, make_unique<Program>());
        Program * program = insert.first->second.get();
        program->weight = weight;
        program->name = name;

        if (scanned == 3){
            regex child_re("[a-z]+");
            auto child_it_begin = cregex_iterator(cbegin(children ), cend(children), child_re);
            auto child_it_end = cregex_iterator();

            for (auto child_it = child_it_begin; child_it != child_it_end; ++child_it){
                auto child_insert = map.emplace(child_it->str(), make_unique<Program>());
                auto * child = child_insert.first->second.get();
                child->parent = program;
                child->name = child_it->str();
                program->children.push_back(child);
            }
        }
    }

    auto root_it = find_if( map.cbegin(), map.cend(), []( const auto & it ) { 
        return it.second->parent == nullptr; 
    });
    
    cout << "Part 1: " << root_it->first << endl;
    root_it->second->computeTotalWeightRecursive();

    for (auto & it : map){
        auto balanced = it.second->isBalanced();

        if (!balanced.first){
            int depth = 0;
            Program * current = it.second.get();
            while ((current = current->parent) != nullptr) ++depth;
            cout << "Part 2: " << it.first << " unbalanced; corrected child weight: "<< balanced.second << "; depth: " << depth << endl;
        }
    }
}