#include <bits/stdc++.h>
using namespace std;

int getMajorityElement(vector<int> nums) {
	int N = nums.size();

	int start = nums[0];
	int cnt = 1;

	for (int idx = 1; idx < N; idx++) {
		if (start == nums[idx]) cnt += 1;
		else cnt -= 1;

		if (cnt < 0) {
			start = nums[idx];
			cnt = 1;
		}
	}

	cnt = 0;
	for (int elt : nums) {
		if (start == elt) cnt += 1;
	}

	return cnt > (N / 2) ? start : -1;
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

	cout << getMajorityElement(nums) << endl;

	return 0;
}