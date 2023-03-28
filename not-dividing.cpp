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
		int N;
		cin >> N;
		vector<int> nums(N);
		for (int idx = 0; idx < N; idx++) {
			cin >> nums[idx];
		}

		// eoeo
		bool makeEven = true;
		for (int idx = 1; idx < N; idx++) {
			if (nums[idx] % nums[idx - 1] == 0) {
				nums[idx] += 1;
			}
		}

		for (int idx = 0; idx < N; idx++) {
			cout << nums[idx] << " ";
		}

		cout << endl;
	}
	return 0;
}