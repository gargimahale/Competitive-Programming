#include <bits/stdc++.h>
using namespace std;

/*
Templates are expanded at compile time. They're like macros.
The simple idea is to pass data type as a parameter so that
we don’t need to write the same code for different data types
 */

template <typename T>
T myMax(T x, T y) {
    return x > y ? x : y;
}

int main(void) {
    cout << myMax<int>(3, 4) << "\n";
    cout << myMax<char>('c', 'd') << "\n";
}