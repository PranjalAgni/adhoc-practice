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
		int N, K;
		cin >> N >> K;
		int len = N * K;
		vector<int> nums(len);
		for (int idx = 0; idx < len; idx++) {
			cin >> nums[idx];
		}

		int medianIndex = ceil(N / 2) - 1;


		int answer = 0;
		while (medianIndex < len) {
			answer += nums[medianIndex];
			medianIndex += N;
		}

		cout << answer << endl;

	}
	return 0;
}