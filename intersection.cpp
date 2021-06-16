#include <bits/stdc++.h>
using namespace std;


long long getSquare(long long val) {
	return val * val;
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N;
	cin >> N;

	vector<int> start(N);
	vector<int> end(N);
	int ans = 0;

	for (int idx = 0; idx < N; idx++) cin >> start[idx];

	for (int idx = 0; idx < N; idx++) cin >> end[idx];

	for (int i = 1; i <= 1000; i++) {
		bool isPossible = true;
		for (int idx = 0; idx < N; idx++) {
			if (i < start[idx] || i > end[idx]) isPossible = false;
		}
		if (isPossible) ans += 1;
	}

	cout << ans << endl;


	return 0;
}