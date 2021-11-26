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

	vector<long long> nums(N);

	for (int idx = 0; idx < N; idx++) {
		cin >> nums[idx];
	}

	long long operations = 0;
	for (int idx = 1; idx < N; idx++) {
		if (nums[idx] < nums[idx - 1]) {
			operations += (nums[idx - 1] - nums[idx]);
			nums[idx] = nums[idx - 1];
		}
	}

	cout << operations << endl;

	return 0;
}