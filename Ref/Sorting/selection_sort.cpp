// TC: O(n)
#include <bits/stdc++.h>

using namespace std;

void selection_sort(vector<int>& arr, int n){
	for(int i=0;i<n-1;++i){
		int min_idx = i;
		for(int j=i+1;j<n;++j){
			if(arr[j]<arr[min_idx]) min_idx = j;

			//swap - Using swap makes it unstable considering duplicates
			//int temp = arr[min_idx];
			//arr[min_idx] = arr[j];
			//arr[j]=temp;

			// Move minimum element at current i -  Stable form
			int key = arr[min_idx];
			while(min_idx>i){
				arr[min_idx]=arr[min_idx-1];
				min_idx--;
			}
			arr[i] = key;
		}
	}
}

int main(){
	vector<int> arr = {5,4,3,2,1};
	selection_sort(arr, arr.size());
	for(int x: arr) cout << x << " ";
	cout << "\n";
	return 0;
}