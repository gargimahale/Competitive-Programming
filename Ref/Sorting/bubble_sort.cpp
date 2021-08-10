// TC: O(n^2)
#include <bits/stdc++.h>

using namespace std;

void bubble_sort(vector<int>& arr, int n){
	bool swapped;
	for(int i=0;i<n;++i){
		swapped = false;
		for(int j=0;j<n-i-1;++j){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int main(){
	vector<int> arr = {5,4,3,2,1};
	bubble_sort(arr, arr.size());
	for(int x: arr) cout << x << " ";
	cout << "\n";
	return 0;
}