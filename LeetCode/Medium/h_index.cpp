#include<bits/stdc++.h>


// https://en.wikipedia.org/wiki/H-index

// Formally, if f is the function that corresponds to the number of citations for each publication, we compute the h-index as follows: First we order the values of f from the largest to the lowest value. Then, we look for the last position in which f is greater than or equal to the position (we call h this position). For example, if we have a researcher with 5 publications A, B, C, D, and E with 10, 8, 5, 4, and 3 citations, respectively, the h-index is equal to 4 because the 4th publication has 4 citations and the 5th has only 3. In contrast, if the same publications have 25, 8, 5, 3, and 3 citations, then the index is 3 because the fourth paper has only 3 citations.

// f(A)=10, f(B)=8, f(C)=5, f(D)=4, f(E)=3　→ h-index=4
// f(A)=25, f(B)=8, f(C)=5, f(D)=3, f(E)=3　→ h-index=3


using namespace std;

bool f(int x, int y){
    return x>y;
}

// // Complexity: O(N)
int solve1(vector<int>& citations) {
    if (citations.empty()) return 0;
    sort(citations.begin(), citations.end(), f);
    for(long long i=0; i<citations.size(); i++){
        if(citations[i]>=i+1) continue;
        else return i--;
    }
    return citations.size();
}

// Complexity: O(LogN) - Binary Search Implementation

int solve(vector<int>& citations) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    if (citations.size()==0) return 0;
    long long l=0, r= citations.size()-1, m;
    while(l<=r){
        m = l+(r-l)/2;
        if(citations[m] == (citations.size()-m)) return citations[m];
        else if(citations[m] > (citations.size()-m)) r = m - 1;
        else l = m + 1;
    }
    return citations.size() - (r+1);
}

int main() {
    vector<int> citations = {0,1,3,5,6};
    int t = 1;
    // cin >> t;
    while(t--) {
      cout << solve(citations) << endl;
    }
    return 0;
}
