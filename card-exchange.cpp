#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int T;
	cin >> T;

	while (T-- > 0) {
		int n, k;
		cin >> n >> k;
		vector<int> nums(n);

		for (int idx = 0; idx < n; idx++) {
			cin >> nums[idx];
		}

		unordered_map<int, int> freqMap;
		for (int& num : nums) {
			freqMap[num] += 1;
		}

		bool isPossible = false;
		for (auto const& itr : freqMap) {
			if (itr.second >= k) {
				isPossible = true;
				break;
			}
		}

		if (isPossible) {
			cout << k - 1 << endl;
		} else {
			cout << n << endl;
		}
	}

	return 0;
}