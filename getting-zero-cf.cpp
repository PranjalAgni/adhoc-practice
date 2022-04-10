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


	for (int idx = 0; idx < N; idx++) {
		int num = nums[idx];
		int ans = INT_MAX;
		for (int add = 0; add < 15; add++) {
			for (int mul = 0; mul < 15; mul++) {
				if (((num + add) * (int)pow(2, mul)) % 32768 == 0) {
					ans = min(ans, add + mul);
				}
			}
		}

		nums[idx] = ans;
	}

	for (int idx = 0; idx < N; idx++) {
		cout << nums[idx] << " ";
	}
	return 0;
}