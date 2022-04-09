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
		vector<long long> a(N), b(N);
		for (int idx = 0; idx < N; idx++) {
			cin >> a[idx];
		}

		for (int idx = 0; idx < N; idx++) {
			cin >> b[idx];
		}

		long long ansA = 0;
		long long ansB = 0;
		for (int idx = 0; idx < N - 1; idx++) {
			long long diffA = abs(a[idx] - a[idx + 1]);
			long long diffB = abs(b[idx] - b[idx + 1]);
			long long currSum = diffA + diffB;
			long long diffC = abs(b[idx] - a[idx + 1]);
			long long diffD = abs(a[idx] - b[idx + 1]);
			long long currSwapSum = diffC + diffD;
			if (currSwapSum < currSum) {
				swap(a[idx], b[idx]);
			}

			ansA += min(currSum, currSwapSum);
		}

		for (int idx = 1; idx < N ; idx++) {
			long long diffA = abs(a[idx] - a[idx - 1]);
			long long diffB = abs(b[idx] - b[idx - 1]);
			long long currSum = diffA + diffB;
			long long diffC = abs(b[idx] - a[idx - 1]);
			long long diffD = abs(a[idx] - b[idx - 1]);
			long long currSwapSum = diffC + diffD;
			if (currSwapSum < currSum) {
				swap(a[idx], b[idx]);
			}

			ansB += min(currSum, currSwapSum);
		}

		cout << min(ansA, ansB) << endl;
	}

	// 72 101 108 108 111 44
	// 10 87 111 114 108 100

	//

	return 0;
}