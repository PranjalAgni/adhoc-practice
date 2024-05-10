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

		for (int k = 2; k < 30; k++) {
			int value = pow(2, k) - 1;
			if (N % value == 0) {
				cout << (N / value) << endl;
				break;
			}
		}
	}
	return 0;
}