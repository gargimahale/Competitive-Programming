#include <bits/stdc++.h>
using namespace std;

class Test {
public:
    double findSalaryCap(double& budget, vector<double>& curr_salary) const {
        int n = curr_salary.size();
        if (n == 0) return 0.0;

        sort(begin(curr_salary), end(curr_salary));

        for (int i = 0; i < n; ++i) {
            int rem = n - i;
            double cap = budget / rem;
            if (cap < curr_salary[i]) {
                return cap;
            } else {
                budget -= curr_salary[i];
            }
        }
        return -1.0;
    }
};

int main(void) {
    Test t;
    double budget;
    int n;
    cin >> n >> budget;
    vector<double> salaries (n);
    for (int i = 0; i < n; ++i) {
        cin >> salaries[i];
    }
    cout << t.findSalaryCap(budget, salaries) << "\n";
}

// TC: O(NlogN)
// SC: O(N)