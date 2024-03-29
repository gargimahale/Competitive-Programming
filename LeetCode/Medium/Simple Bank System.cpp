#include <bits/stdc++.h>
using namespace std;

class Bank {
public:
    vector<long long> balance;
    Bank(vector<long long>& balance) {
        this->balance = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 >= 0 && account1 <= balance.size() && account2 >= 0 && account2 <= balance.size()){
            long long acc1 = balance[account1-1];
            long long acc2 = balance[account2-1];

            if (acc1 >= money){
                balance[account1-1] -= money;
                balance[account2-1] += money;
                return true;
            }
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if (account >= 0 && account <= balance.size()){
            balance[account-1] += money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if (account >= 0 && account <= balance.size() && balance[account-1] >= money){
            balance[account-1] -= money;
            return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */