#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N, M;
	cin >> N >> M;
	vector<int> price(N);
	for (int idx = 0; idx < N; idx++) {
		cin >> price[idx];
	}

	sort(price.begin(), price.end());
	int answer = 0;
	for (int idx = 0; idx < M; idx++) {
		if (price[idx] > 0) {
			break;
		}
		answer += abs(price[idx]);
	}

	cout << answer << endl;
	return 0;
}
