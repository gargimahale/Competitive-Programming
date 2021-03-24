#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    uint32_t reverseBits(uint32_t n){
        bitset<32> b(n);
        string str = b.to_string();
        reverse(begin(str), end(str));
        bitset<32> a(str);
        return a.to_ulong();
    }
};
