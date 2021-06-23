#include <bits/stdc++.h>
using namespace std;

// Time: O(N * N) | Space: O(N)
int findLIS(vector<int> nums, int N) {
	vector<int> lisEndingHere(N);
	lisEndingHere[0] = 1;
	int maxLengthSeq = 1;

	for (int idx = 1; idx < N; idx++) {
		int currMax = 0;
		for (int jdx = 0; jdx < idx; jdx++) {
			if (nums[jdx] < nums[idx]) {
				currMax = max(currMax, lisEndingHere[jdx]);
			}
		}

		lisEndingHere[idx] = currMax + 1;
		maxLengthSeq = max(maxLengthSeq, lisEndingHere[idx]);
	}

	return maxLengthSeq;
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

	cout << findLIS(nums, N) << endl;
	return 0;
}