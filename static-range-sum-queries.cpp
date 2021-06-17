#include <bits/stdc++.h>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N, Q;

	cin >> N >> Q;

	vector<int> nums(N);

	for (int idx = 0; idx < N; idx++) {
		cin >> nums[idx];
	}

	vector<int> prefixSum(N);
	prefixSum[0] = nums[0];

	for (int idx = 1; idx < N; idx++) {
		prefixSum[idx] = nums[idx] + prefixSum[idx - 1];
	}

	for (int q = 0; q < Q; q++) {
		int a, b;
		cin >> a >> b;

		int low = (a - 2) < 0 ? 0 : prefixSum[a - 2];
		int answer = prefixSum[b - 1] - low;

		cout << answer << endl;
	}


	return 0;
}