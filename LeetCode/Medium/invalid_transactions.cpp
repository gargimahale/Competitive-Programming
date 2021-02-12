#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    struct Person{
        int time, amount;
        string city, name;
    };

    vector<string> invalidTransactions(vector<string>& transactions) {
        int n = transactions.size();
        vector<Person> ns(transactions.size());
        vector<string> ans;
        for(int i = 0; i < n; ++i){
            string temp(transactions[i]);
            for (auto& c: temp){
                if (c == ','){
                    c = ' ';
                }
            }
            stringstream ss(temp);
            ss >> ns[i].name >> ns[i].time >> ns[i].amount >> ns[i].city;
        }
        for (int i=0;i<n;++i){
            if (ns[i].amount > 1000){
                ans.push_back(transactions[i]);
                continue;
            }
            bool found = false;
            for (int j=0;j<n;++j){
                if (i == j) continue;
                if (abs(ns[i].time - ns[j].time) <= 60 && ns[i].name == ns[j].name && ns[i].city != ns[j].city){
                    found = true;
                    break;
                }
            }
            if (found){
                ans.push_back(transactions[i]);
            }
        }
        return ans;
    }
};