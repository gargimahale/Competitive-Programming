#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string a = "ab";

    // starting form position 0 copy 0 chars and start copying chars from [i+1, ..]
    cout << a.substr(0, 0) << " " << a.substr(0 + 1);
    // cout << "Hello World!";
    // return 0;
}