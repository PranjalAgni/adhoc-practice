#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	long long N, K;
	cin >> N >> K;

	long long oddElements = N / 2;
	if (N % 2 != 0) oddElements += 1;
	if (K <= oddElements) {
		// will be in odd
		cout << (2 * K) - 1 << endl;
	} else {
		// will be in even
		cout << 2 * (K - oddElements) << endl;
	}
	return 0;
}
