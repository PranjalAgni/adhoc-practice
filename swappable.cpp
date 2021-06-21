#include <bits/stdc++.h>
using namespace std;

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

	int cnt = 0;

	for (int idx = 0; idx < N - 1; idx++) {
		for (int jdx = idx + 1; jdx < N; jdx++) {
			if (nums[idx] != nums[jdx]) cnt += 1;
		}
	}

	cout << cnt << endl;

	return 0;
}