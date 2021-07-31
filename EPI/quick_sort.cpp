#include <bits/stdc++.h>
using namespace std;

typedef enum {RED, WHITE, BLUE} Color;

void DutchFlagPartitioning(int pivot_idx, vector<Color>* A_ptr) {
    vector<Color>& A = *A_ptr;
    Color pivot = A[pivot_idx];

    // int smaller = 0;
    // // get elements smaller than pivot
    // for (int i = 0; i < A.size(); ++i) {
    //     if (A[i] < pivot) {
    //         swap(A[i], A[smaller++]);
    //     }
    // }

    // int larger = A.size() - 1;
    // // group elements larger than pivot
    // for (int j = A.size() - 1; j >= 0; --j) {
    //     if (A[j] > pivot) {
    //         swap(A[j], A[larger--]);
    //     }
    // }

    // OR with the help of 3 variables

    int smaller = 0, equal = 0, larger = A.size();
    while (equal < larger) {
        if (A[equal] < pivot) {
            swap(A[equal++], A[smaller++]);
        }
        else if (A[equal] == pivot) {
            ++equal;
        }
        else {
            swap(A[equal], A[--larger]);
        }
    }
}

int main(void) {
    vector<Color> A = {RED, WHITE, BLUE, WHITE, RED, RED, RED, WHITE, BLUE, WHITE, BLUE, BLUE};
    DutchFlagPartitioning(3, &A);
    for (auto ele : A) {
        cout << ele << " ";
    }
}