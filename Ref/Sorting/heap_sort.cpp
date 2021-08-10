#include <bits/stdc++.h>
using namespace std;

// To heapify a subtree rooted with node i which is
// an index in arr. n is size of heap
void heapify(vector<int>& arr, int n, int i) {
	int largest = i; // Initialize largest as root
	int l = 2*i + 1; // left = 2*i + 1
	int r = 2*i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < n && arr[l] > arr[largest]) largest = l;

	// If right child is larger than largest so far
	if (r < n && arr[r] > arr[largest]) largest = r;

	// If largest is not root
	if (largest != i) {
		swap(arr[i], arr[largest]);
		// Recursively heapify the affected sub-tree
		heapify(arr, n, largest);
	}
}

void heapSort(vector<int>& arr, int n)
{
	// Making max heap and updating the array
	for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
	// One by one extract an element from heap
    cout << endl;

	for (int i=n-1; i>0; i--) {
		// Move current root to end
		swap(arr[0], arr[i]);
		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

int main() {
    vector<int> arr = {5,4,3,2,1};
	heapSort(arr, arr.size());
	for(int x: arr) cout << x << " ";
	cout << "\n";
	return 0;
}
