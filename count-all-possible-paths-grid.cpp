#include <bits/stdc++.h>
using namespace std;

int totalUniquePaths(int rows, int cols) {
	if (rows == 1 || cols == 1) return 1;
	return totalUniquePaths(rows - 1, cols) + totalUniquePaths(rows, cols - 1);
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int rows, cols;
	cin >> rows >> cols;

	cout << totalUniquePaths(rows, cols) << endl;
	return 0;
}
