#include <bits/stdc++.h>
using namespace std;

class StockPrice {
public:
    unordered_map<int, int> mp;
    multiset<int> prices;
    int last_timestamp = 0, last_price = 0;
    
    StockPrice() {}
    
    void update(int timestamp, int price) {
        auto it = mp.find(timestamp);
        if (it != mp.end()){
            prices.erase(prices.find(it->second));
        }
        
        prices.insert(price);
        mp[timestamp] = price;
        
        if (timestamp >= last_timestamp){
            last_timestamp = timestamp;
            last_price = price;
        }
    }
    
    int current() {
        return last_price;
    }
    
    int maximum() {
        return *rbegin(prices);
    }
    
    int minimum() {
        return *begin(prices);
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */