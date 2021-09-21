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
		vector<int> strength(N);
		for (int idx = 0; idx < N; idx++) cin >> strength[idx];

		int answer = INT_MAX;
		for (int idx = 0; idx < N; idx++) {
			for (int jdx = idx + 1; jdx < N; jdx++) {
				answer = min(answer, abs(strength[idx] - strength[jdx]));
			}
		}

		cout << answer << endl;
	}


	return 0;
}