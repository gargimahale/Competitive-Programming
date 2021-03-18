#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
long long w, h, n;

bool good(long long x){
    return (x/w)*(x/h) >= n;
}

int main(){
    IOS
    cin >> w >> h >> n;
    long long l = 0;
    long long r = 1;

    while(!good(r)) r *= 2;

    while(r > l+1){
        long long m = l+(r-l)/2;
        if (good(m)){
            r = m;
        }
        else{
            l = m;
        }
    }

    cout << r;
    return 0;
}


