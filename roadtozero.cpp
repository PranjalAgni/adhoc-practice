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
		long long x, y;
		cin >> x >> y;
		long long a, b;
		cin >> a >> b;
		if (x == 0 && y == 0) {
			cout << 0 << endl;
		} else if (x == 0) {
			cout << y * min(a, b) << endl;
		} else if (y == 0) {
			cout << x * min(a, b) << endl;
		} else {
			long long diff = abs(x - y);
			long long price1 = diff * a + b  * min(x, y);
			long long price2 = diff * a + a * min(x, y) * 2;
			cout << min(price1, price2) << endl;
		}
	}
	return 0;
}