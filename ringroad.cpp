#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	vector<int> houses(m);
	for (int idx = 0; idx < m; idx++) {
		cin >> houses[idx];
	}

	int currentHouse = 1;
	int idx = 0;
	int answer = 0;
	while (idx < m) {
		if (currentHouse <= houses[idx]) {
			answer += houses[idx] - currentHouse;
		} else {
			//  1 2 3 4 5 6
			int distance = (n - currentHouse) + houses[idx];
			answer += distance;
		}

		currentHouse = houses[idx];
		idx += 1;
	}

	cout << answer << endl;
	return 0;
}
