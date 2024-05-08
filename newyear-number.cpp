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

		if (N < 2020) cout << "NO" << endl;
		else {
			int lastDigit = N % 10;
			bool isPossible = false;
			int factor = N / 2021;
			for (int f = factor; f >= 0; f--) {
				int num = N - (2021 * f);
				if (num % 2020 == 0) {
					isPossible = true;
					break;
				}
			}

			cout << ((isPossible) ? "YES" : "NO") << endl;
		}
	}
	return 0;
}
