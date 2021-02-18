#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int miles, time, prevTime, res;
    while(true){
        cin >> n;
        if (n == -1) break;
        res = 0, prevTime = 0;
        for(int i=0; i<n; ++i){
            cin >> miles >> time;
            res += miles * (time-prevTime);
            prevTime = time;
        }
        cout << res << " miles\n";
    }
    return 0;
}