#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif


	int N, X;
	cin >> N >> X;

	vector<pair<int, int>> nums(N);
	int current;
	for (int idx = 0; idx < N; idx++) {
		cin >> current;
		nums[idx] = {current, idx + 1};
	}

	sort(nums.begin(), nums.end());

	bool isFound = false;
	for (int idx = 0; idx < N; idx++) {
		int left = idx + 1;
		int right = N - 1;
		isFound = false;
		while (left < right) {
			int sum = nums[idx].first + nums[left].first + nums[right].first;
			if (sum == X) {
				cout << nums[idx].second << " " << nums[left].second << " " << nums[right].second << endl;
				isFound = true;
				break;
			} else if (sum > X) {
				right -= 1;
			} else {
				left += 1;
			}
		}

		if (isFound) break;
	}

	if (!isFound) cout << "IMPOSSIBLE" << endl;
	return 0;
}