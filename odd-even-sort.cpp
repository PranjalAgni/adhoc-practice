#include <bits/stdc++.h>
using namespace std;


void printArray(vector<int> array) {
	for (int elt : array) {
		cout << elt << " ";
	}
	cout << endl;
}

vector<int> oddEvenSort(vector<int>& array) {
	int N = array.size();
	int low = 0;
	int high = N - 1;
	sort(array.begin(), array.end());

	while (low < high) {
		if (array[high] % 2 != 0) {
			swap(array[low], array[high]);
			high += 1;
			low += 1;
		}

		high -= 1;
	}

	sort(array.begin() + low + 1, array.end());

	return array;

}

vector<int> oddEvenSort2(vector<int>& array) {
	int N = array.size();
	int low = 0;
	int high = N - 1;
	int oddElt = 0;

	while (low < high) {
		// get the left even element
		while (array[low] % 2 != 0) {
			low += 1;
			oddElt += 1;
		}

		// get the right odd element
		while (array[high] % 2 == 0 && low < high) {
			high -= 1;
		}

		// swap them
		if (low < high) {
			swap(array[low], array[high]);
		}

	}


	sort(array.begin(), array.begin() + oddElt, greater<int>());
	sort(array.begin() + oddElt, array.end());
	return array;

}


int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N;
	cin >> N;
	vector<int> nums(N);
	for (int idx = 0; idx < N; idx++) {
		cin >> nums[idx];
	}

	printArray(oddEvenSort2(nums));

	return 0;
}