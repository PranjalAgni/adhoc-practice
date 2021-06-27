#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int k) {
	int idx = 0;
	int N = nums.size();
	int sum = 0;
	int ans = -1;

	while (idx < N) {
		sum += nums[idx];
		if (sum <= k) ans = idx;
		idx += 1;
	}

	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N, K;
	cin >> N >> K;

	vector<int> nums(N);

	for (int idx = 0; idx < N; idx++) {
		cin >> nums[idx];
	}

	cout << solve(nums, K) << endl;
	return 0;
}