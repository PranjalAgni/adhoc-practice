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
		int N;
		cin >> N;
		if (N == 1) cout << 0 << endl;
		else if (N % 3 != 0) cout << -1 << endl;
		else {
			int ans = 0;
			while (N != 1) {
				if (N % 3 != 0) {
					ans = -1;
					break;
				}
				if (N % 6 == 0) N = N / 6;
				else N *= 2;
				ans += 1;
			}

			cout << ans << endl;
		}

	}
	return 0;
}