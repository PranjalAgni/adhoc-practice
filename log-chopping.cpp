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
		vector<int> arr(N);
		for (int idx = 0; idx < N; idx++) {
			cin >> arr[idx];
		}

		sort(arr.begin(), arr.end());
		reverse(arr.begin(), arr.end());
		int turn = 0;
		bool shouldContinue = true;

		while (shouldContinue) {
			int val = arr[0];
			arr.erase(arr.begin());
			if (val == 1) {
				shouldContinue = false;
				continue;
			} else if (val % 2 == 0) {
				arr.push_back(val);
				arr.push_back(val);
			} else {
				int y = val / 2;
				int z = val - y;
				arr.push_back(y);
				arr.push_back(z);
			}

			sort(arr.begin(), arr.end());
			reverse(arr.begin(), arr.end());
			if (turn == 0) turn = 1;
			else turn = 0;
		}

		if (turn == 0) cout << "maomao90" << endl;
		else cout << "errorgorn" << endl;
	}

	/**
	 *
	 *
	 * 2 4 2 1
	 4 2 2 1

	**/
	return 0;
}