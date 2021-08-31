#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
using namespace std;

int main(void) {
    int N;
    cin >> N;
    if (N < 4 || N & 1){
    	cout << "NO\n";
    }
    else{
    	cout << "YES\n";
    }
}
