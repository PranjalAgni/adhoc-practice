#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int n, q;
	cin >> n >> q;
	vector<long long> prices(n);
	for (int idx = 0; idx < n; idx++) {
		cin >> prices[idx];
	}

	sort(prices.begin(), prices.end());
	vector<long long> prefixSum(n + 1);
	prefixSum[0] = 0;
	for (int idx = 0; idx < n; idx++) {
		prefixSum[idx + 1] = prefixSum[idx] + prices[idx];
	}


	while (q-- > 0) {
		int x, y;
		cin >> x >> y;

		cout << prefixSum[n - x + y] - prefixSum[n - x] << endl;

	}
	return 0;

}