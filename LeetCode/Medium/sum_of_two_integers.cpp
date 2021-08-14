#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int getSum(int a, int b){
        int sum = a;
        while(b){
            sum = a ^ b;
            b = (a & b) << 1;
            a = sum;
        }
        return sum;
    }
};

int32_t main(void){
    Solution S;
    cout << S.getSum(25, 30) << "\n";
}