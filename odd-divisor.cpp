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
		long long N;
		cin >> N;
		while (N % 2 == 0) {
			N = N / 2;
		}

		if (N == 1) cout << "NO" << endl;
		else cout << "YES" << endl;
	}
	return 0;
}