// https://codeforces.com/contest/1380/problem/A
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
		vector<int> elements(N);
		for (int idx = 0; idx < N; idx++) cin >> elements[idx];
		bool isPossible = false;
		for (int jdx = 1; jdx < N; jdx++) {
			int pj = elements[jdx];
			int piIdx = -1;
			int pkIdx = -1;
			for (int idx = 0; idx < jdx; idx++) {
				if (elements[idx] < pj) {
					piIdx = idx;
					break;
				}
			}

			for (int kdx = jdx + 1; kdx < N; kdx++) {
				if (elements[kdx] < pj) {
					pkIdx = kdx;
					break;
				}
			}

			if (piIdx != -1 && pkIdx != -1) {
				isPossible = true;
				cout << "YES" << endl;
				cout << (piIdx + 1) << " " << (jdx + 1) << " " << (pkIdx + 1) << endl;
				break;
			}
		}

		if (!isPossible) cout << "NO" << endl;
	}
	return 0;
}