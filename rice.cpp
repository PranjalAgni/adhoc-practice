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
		int n, a, b, c, d;
		cin >> n >> a >> b >> c >> d;

		int x = n * (a - b);
		int y = n * (a + b);

		int p = (c - d);
		int q = (c + d);

		if (y < p || q < x) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}


	}
	return 0;
}