#include <bits/stdc++.h>
using namespace std;


long long getSquare(long long val) {
	return val * val;
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N;
	cin >> N;

	string S;
	cin >> S;

	int Q;
	cin >> Q;

	int len = 2 * N;

	bool isSwapped = false;
	for (int q = 0; q < Q; q++) {
		int T, A, B;
		cin >> T >> A >> B;

		if (T == 1) {
			int aNew = A - 1;
			int bNew = B - 1;

			if (isSwapped) {
				aNew += N;
				bNew += N;
			}

			aNew %= len;
			bNew %= len;
			swap(S[aNew], S[bNew]);
		} else {
			isSwapped = !isSwapped;
		}
	}

	if (isSwapped) {
		int first = 0;
		int second = N;
		while (first < N && second < len) {
			swap(S[first], S[second]);
			first += 1;
			second += 1;
		}
	}

	cout << S << endl;
	return 0;
}