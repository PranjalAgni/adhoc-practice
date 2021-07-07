#include <bits/stdc++.h>
using namespace std;

bool solve(vector<int>& nums, int k) {
	int low = 0;
	int high = nums.size() - 1;

	while (low < high) {
		int sum = nums[low] + nums[high];
		if (sum == k) return true;
		else if (sum < k) low += 1;
		else high -= 1;
	}

	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	cout << solve({1, 2, 3}, 4) << endl;
	return 0;
}