#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif


	int n, b, d;
	cin >> n >> b >> d;
	vector<int> arr(n);
	for (int idx = 0; idx < n; idx++) {
		cin >> arr[idx];
	}

	int answer = 0;
	int waste = 0;
	for (int idx = 0; idx < n; idx++) {
		if (arr[idx] <= b) {
			waste += arr[idx];
		}

		if (waste > d) {
			answer += 1;
			waste = 0;
		}
	}

	cout << answer << endl;
	return 0;
}