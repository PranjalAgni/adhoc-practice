#include <bits/stdc++.h>
using namespace std;

void inputList(vector<int>& arr, int len) {
	for (int idx = 0; idx < len; idx++) {
		cin >> arr[idx];
	}

	return;
}

void printArray(vector<int> array) {
	for (int elt : array) {
		cout << elt << " ";
	}

	cout << endl;
}

// Time: O(MlogM) | Space: O(abs(M - N))
vector<int> mergeSortedArray(vector<int>& nums1, vector<int> nums2) {
	int N = nums1.size();
	int M = nums2.size();
	int start1 = 0;
	int start2 = 0;

	while (start1 < N || start2 < M) {
		if (start1 < N && start2 < M) {
			if (nums1[start1] < nums2[start2]) {
				start1 += 1;
			} else {
				swap(nums1[start1], nums2[start2]);
				start1 += 1;
				sort(nums2.begin(), nums2.end());
			}
		} else if (start2 < M) {
			nums1.push_back(nums2[start2]);
			start2 += 1;
		} else {
			start1 += 1;
		}
	}

	return nums1;
}

// Time: O(N + M) | Space: O(N + M)
vector<int> mergeSortedArray2(vector<int>& nums1, vector<int> nums2) {
	int N = nums1.size();
	int M = nums2.size();
	int start1 = 0;
	int start2 = 0;
	vector<int> mergedNums(N + M);
	int pos = 0;
	while (start1 < N || start2 < M) {
		if (start1 < N && start2 < M) {
			if (nums1[start1] < nums2[start2]) {
				mergedNums[pos] = nums1[start1];
				start1 += 1;
			} else {
				mergedNums[pos] = nums2[start2];
				start2 += 1;
			}
		} else if (start1 < N) {
			mergedNums[pos] = nums1[start1];
			start1 += 1;
		} else {
			mergedNums[pos] = nums2[start2];
			start2 += 1;
		}

		pos += 1;
	}

	return mergedNums;
}


vector<int> mergeSortedArray2(vector<int>& nums1, vector<int> nums2) {
	int N = nums1.size();
	int M = nums2.size();
	int start1 = 0;
	int start2 = 0;
	vector<int> mergedNums(N + M);
	int pos = 0;
	while (start1 < N || start2 < M) {
		if (start1 < N && start2 < M) {
			if (nums1[start1] < nums2[start2]) {
				mergedNums[pos] = nums1[start1];
				start1 += 1;
			} else {
				mergedNums[pos] = nums2[start2];
				start2 += 1;
			}
		} else if (start1 < N) {
			mergedNums[pos] = nums1[start1];
			start1 += 1;
		} else {
			mergedNums[pos] = nums2[start2];
			start2 += 1;
		}

		pos += 1;
	}

	return mergedNums;

	int getMedianOfSortedArray(vector<int> nums) {
		int N = nums.size();
		int medianIdx = N / 2;
		int medianValue = nums[medianIdx];
		if (N % 2 == 0) {
			medianValue	+= nums[medianIdx - 1];
			medianValue /= 2;
		}

		return medianValue;
	}

	int main() {
#ifndef ONLINE_JUDGE
		// for getting input from input.txt
		freopen("input.txt", "r", stdin);
		// for writing output to output.txt
		freopen("output.txt", "w", stdout);
#endif

		int N, M;
		cin >> N >> M;
		vector<int> nums1(N);
		vector<int> nums2(M);

		inputList(nums1, N);
		inputList(nums2, M);
		vector<int> mergedSortedNum = mergeSortedArray2(nums1, nums2);
		printArray(mergedSortedNum);
		cout << getMedianOfSortedArray(mergedSortedNum) << endl;
		return 0;
	}