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
		int a, b;
		cin >> a >> b;

		if (a == 0) cout << 1 << endl;
		else {
			int totalMoney = a + 2 * b;
			cout << totalMoney + 1 << endl;
		}

	}
	return 0;
}