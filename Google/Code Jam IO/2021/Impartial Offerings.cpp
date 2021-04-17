#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, j = 0;
    cin >> T;
    while (T--) {
        int n, ele;
        cin >> n;
        int arr[101] = {0};
        for (int i = 0; i < n; ++i) {
            cin >> ele;
            arr[ele]++;
        }
        int cnt = 0, check = 1;
        for (int i = 0; i < 101; ++i) {
            if (arr[i] > 0) {
                cnt += (check++ * arr[i]);
            }
        }

        cout << "Case #" << ++j << ": " << cnt << "\n";
    }
    return 0;
}