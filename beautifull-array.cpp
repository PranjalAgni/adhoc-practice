#include <bits/stdc++.h>
using namespace std;

int greatestNumber(int s, int k, int b) {
	int answer = b * k;
	return answer + (k - 1);
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int T;
	while (T-- > 0) {
		int n, k, b, s;
		cin >> n >> k >> b >> s;

		int avg = s / k;
		if (avg < b) {
			cout << -1 << endl;
		} else {
			int maxValue = greatestNumber(s, k, b);
			int remaining = s - maxValue;
			int formed = 1;
			while (formed <= n) {
				if (remaining >= (k - 1)) {
					cout << k - 1 << " ";
					remaining -= (k - 1);
				} else if (remaining > 0) {
					cout << remaining << " ";
					remaining = 0;
				} else {
					cout << 0 << " ";
				}

				formed += 1;
			}

			cout << maxValue << endl;
			// we can construct the array here
			// find the greatest element when divided by `k` returns max value

		}
	}

	return 0;
}


// n,k,b,s

// 1,6,3,100

// 3,6,3,19
// x1/k + x2/k + x3/k