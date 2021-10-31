#include <bits/stdc++.h>
using namespace std;

int main(void){
	int a[3];
	long long area = 0;

	FILE *fp = fopen("input.txt", "r+");

	while(fscanf(fp, "%dx%dx%d", a, a+1, a+2) != -1){
		sort(a, a+3);
		// part 1
		// area += 2 * (a[0] * a[1] + a[1] * a[2] + a[2] * a[0]) + a[0] * a[1];
		
		// part 2
		area += (2 * (a[0] + a[1])) + (a[0] * a[1] * a[2]);
	}
	cout << area << "\n";
}