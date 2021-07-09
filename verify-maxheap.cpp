#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& nums) {
	int N = nums.size();

	for (int idx = 0; idx < N; idx++) {
		int first = 2 * idx + 1;
		int second = 2 * idx + 2;
		if (first < N && nums[first] > nums[idx]) return false;
		if (second < N && nums[second] > nums[idx]) return false;
	}

	return true;
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

	cout << solve(nums) << endl;
	return 0;
}