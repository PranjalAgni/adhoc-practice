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

		bool isPossible = true;
		int mx = 0;

		for (int idx = 0; idx < N; idx++) {
			int current = nums[idx];
			int x = current / 10;
			int y = current % 10;

			if (x <= y && mx <= x) {
				mx = y;
			} else if (mx <= current) {
				mx = current;
			} else {
				isPossible = false;
				break;
			}
		}

		if (isPossible) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}

	}
	return 0;
}

// [12,3,45,67]
// 12,3,45,67


// if both are >=10
// decide which to expand
// check if elt can be expanded?
// if only one can be expanded then we need to expand it
// if both can be expanded then greedily we can select idx + 1 because
// it will not break sorting i guess!!!

//