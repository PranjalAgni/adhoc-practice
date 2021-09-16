#include <bits/stdc++.h>
using namespace std;

vector<int> countSort(vector<int>& array) {
	int low = 0;
	int mid = 0;
	int high = array.size() - 1;

	while (mid < high) {
		int elt = array[mid];
		if (elt == 0) {
			swap(array[low], array[mid]);
			low += 1;
			mid += 1;
		} else if (elt == 1) {
			mid += 1;
		} else {
			swap(array[mid], array[high]);
			high -= 1;
		}
	}

	return array;
}

void printArray(vector<int> array) {
	for (int elt : array) {
		cout << elt << " ";
	}
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	vector<int> array = {0, 1, 2, 1, 2, 0, 1, 1, 1};
	countSort(array);
	printArray(array);
	return 0;
}