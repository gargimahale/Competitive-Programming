#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio (false);
    cin.tie(0);

    int h, w;
    cin >> h >> w;
    vector<string> board(h);

    for (int i=0; i<h; ++i){
        cin >> board[i];
    }

    int i = 0, j = 0;
    int ans = board[0][0] == '*';

    while(i < h-1 || j < w-1){
        if (j == w-1 || (i < h-1 && board[i+1][j] == '*')){
            ++i;
        }else ++j;

        ans += (board[i][j] == '*');
    }
    cout << ans << "\n";
    return 0;
}