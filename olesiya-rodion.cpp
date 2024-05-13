#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	long long n, t;
	cin >> n >> t;
	if (t == 10) {
		if (n == 1) {
			cout << -1 << endl;
		} else {
			while (n-- > 1) cout << 1;
			cout << 0 << endl;
		}
	} else {
		while (n-- > 0) cout << t;
		cout << endl;
	}
	return 0;
}