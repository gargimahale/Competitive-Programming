#include <bits/stdc++.h>
using namespace std;

int main(void){
    long long T, N, M, sum, in;
    cin >> T;
    for (int j = 0; j < T; ++j){
        cin >> N >> M;
        sum = 0;
        for (long long i = 0; i < N; ++i){
            cin >> in;
            sum += in;
        }
        
        cout << "Case #" << j+1 << ": " << sum%M << "\n";
    }
}