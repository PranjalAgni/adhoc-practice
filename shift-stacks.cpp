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
		vector<long long> stacks(N);
		for (int idx = 0; idx < N; idx++) {
			cin >> stacks[idx];
		}

		int curr = 0;
		bool isPossible = true;
		long long remaining = 0;

		for (int idx = 0; idx < N; idx++) {
			remaining += stacks[idx];
			if (curr > remaining) {
				isPossible = false;
				break;
			} else {
				remaining -= curr;
			}
			curr += 1;
		}

		cout << (isPossible ? "YES" : "No") << endl;
	}
	return 0;
}