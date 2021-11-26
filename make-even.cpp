// https://codeforces.com/contest/1611/problem/A

#include <bits/stdc++.h>
using namespace std;

bool isEven(int num) {
	return (num % 2) == 0;
}

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

		if (isEven(N)) cout << 0 << endl;
		else {
			int temp = N;
			bool isEvenDigitExists = false;
			bool isFirstDigitEven = false;
			while (temp != 0) {
				int digit = temp % 10;
				if (!isEvenDigitExists && isEven(digit)) isEvenDigitExists = true;
				isFirstDigitEven = isEven(digit);
				temp /= 10;
			}

			if (!isEvenDigitExists) cout << -1 << endl;
			else {
				if (isFirstDigitEven) cout << 1 << endl;
				else cout << 2 << endl;
			}
		}

	}
	return 0;
}