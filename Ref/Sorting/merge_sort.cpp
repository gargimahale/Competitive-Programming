// Merge sort in C++


#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int start, int middle, int end) {

    vector<int> lft_arr(middle - start + 1);
    vector<int> rght_arr(end - middle);

    // fill in left and right arrays
    for (int i = 0; i < lft_arr.size(); ++i)
        lft_arr[i] = arr[start + i];
    for (int i = 0; i < rght_arr.size(); ++i)
        rght_arr[i] = arr[middle + 1 + i];

    int lft_idx = 0, rght_idx = 0, curr_idx=start;

    while (lft_idx < lft_arr.size() && rght_idx < rght_arr.size()) {
        if (lft_arr[lft_idx] <= rght_arr[rght_idx]) {
            arr[curr_idx++] = lft_arr[lft_idx++];
        } else {
            arr[curr_idx++] = rght_arr[rght_idx++];
        }
    }
    // copy remaining elements of leftArray[] if any
    while (lft_idx < lft_arr.size()) arr[curr_idx++] = lft_arr[lft_idx++];
    // copy remaining elements of rightArray[] if any
    while (rght_idx < rght_arr.size()) arr[curr_idx++] = rght_arr[rght_idx++];
}

void mergeSort(vector<int> &arr, int start, int end) {
    if (start < end) {
        int middle = (start + end) / 2;
        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);
        merge(arr, start, middle, end);
    }
}

int main() {
    vector<int> arr = {12, 10, 9, 1, 2, 3, 13, 14, 4, 5, 6, 7, 8};
    mergeSort(arr, 0, arr.size() - 1);
    for (int i=0; i < arr.size(); i++) cout << arr[i] << " ";
    return 0;
}