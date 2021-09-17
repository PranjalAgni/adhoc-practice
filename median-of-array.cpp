#include <bits/stdc++.h>
using namespace std;

int getMedianValue(vector<int> nums) {
	int N = nums.size();
	int medianIdx = N / 2;
	int medianValue = nums[medianIdx];
	if (N % 2 == 0) {
		medianValue += nums[medianIdx - 1];
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

	int N;
	cin >> N;

	// sorted order already
	vector<int> nums(N);

	for (int idx = 0; idx < N; idx++) {
		cin >> nums[idx];
	}

	cout << getMedianValue(nums) << endl;
	return 0;
}