#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& array, int low, int mid, int high) {
	int N1 = mid - low + 1;
	int N2 = high - mid;
	vector<int> nums1(N1);
	vector<int> nums2(N2);

	for (int idx = 0; idx < N1; idx++) {
		nums1[idx] = array[low + idx];
	}

	for (int idx = 0; idx < N2; idx++) {
		nums2[idx] = array[mid + 1 + idx];
	}

	int left1 = 0;
	int left2 = 0;
	int pos = low;

	while (left1 < N1 || left2 < N2) {
		if (left1 < N1 && left2 < N2) {
			if (nums1[left1] < nums2[left2]) {
				array[pos] = nums1[left1];
				left1 += 1;
			} else {
				array[pos] = nums2[left2];
				left2 += 1;
			}
		} else if (left1 < N1) {
			array[pos] = nums1[left1];
			left1 += 1;
		} else {
			array[pos] = nums2[left2];
			left2 += 1;
		}

		pos += 1;
	}
}

void mergeSortHelper(vector<int>& array, int low, int high) {
	if (low >= high) return;
	int mid = low + (high - low) / 2;

	mergeSortHelper(array, low, mid);
	mergeSortHelper(array, mid + 1, high);
	merge(array, low, mid, high);
}


vector<int> mergeSort(vector<int>& array) {
	int N = array.size();
	mergeSortHelper(array, 0, N - 1);
	return array;
}

void print(vector<int>& array) {
	for (int elt : array) {
		cout << elt << " ";
	}

	cout << endl;
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

	vector<int> array(N);
	for (int idx = 0; idx < N; idx++) {
		cin >> array[idx];
	}

	string word = "hello";
	for (int idx = 0; idx < word.length(); idx++) {
		word[idx] ^= 256;
	}

	cout << word << endl;
	mergeSort(array);
	print(array);
	return 0;
}