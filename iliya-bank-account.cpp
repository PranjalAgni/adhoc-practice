#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N;
	cin >> N;

	if (N > 0) cout << N << endl;
	else {
		N *= -1;
		int last = N % 10;
		int secondLast = (N / 10) % 10;
		if (last > secondLast) {
			cout << -(N / 10) << endl;
		} else {
			cout << -((N / 100) * 10 + last);
		}
	}
	return 0;
}