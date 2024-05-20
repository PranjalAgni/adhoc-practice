#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N, target;
	cin >> N >> target;
	vector<int> cells(N);
	for (int idx = 0; idx < N; idx++) {
		cin >> cells[idx];
	}

	int idx = 0;
	bool isPossible = false;
	while (idx < N) {
		int current = (idx + 1) + cells[idx];
		if (current == target) {
			isPossible = true;
			break;
		} else if (current > target) {
			break;
		}

		idx = current - 1;
	}

	if (isPossible) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
