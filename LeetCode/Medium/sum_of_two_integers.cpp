#include<bits/stdc++.h>

using namespace std;

int getSum(int a, int b){
    if(b == 0){
        return a;
    }
    int sum = a^b;
    int carry = (unsigned int) (a & b) << 1;
    return getSum(sum, carry);
}

int main(void){
    cout << getSum(2, 3) << "\n";
}