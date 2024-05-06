#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N;
	cin >> N;
	vector<int> coins(N);
	int sum = 0;

	for (int idx = 0; idx < N; idx++) {
		cin >> coins[idx];
		sum += coins[idx];
	}

	// sort in desc order
	sort(coins.rbegin(), coins.rend());
	int yourOtherTwin = 0;
	int idx = 0;
	for (; idx < N; idx++) {
		yourOtherTwin += coins[idx];
		sum -= coins[idx];
		if (yourOtherTwin > sum) {
			break;
		}
	}

	cout << idx + 1 << endl;

	return 0;
}