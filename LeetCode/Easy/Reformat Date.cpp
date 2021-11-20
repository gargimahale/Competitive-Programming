#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reformatDate(string date) {
        unordered_map<string, string> months = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"},{"Apr", "04"}, {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"},{"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"}};
        
        istringstream iss(date);
        string day; iss >> day;
        
        day.pop_back(); day.pop_back();
        
        if (day.size() == 1)
            day = "0" + day;
        
        string month; iss >> month;
        string year; iss >> year;
        return year + "-" + months[month] + "-" + day;
    }
};