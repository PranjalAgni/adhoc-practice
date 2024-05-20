#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int a, b;
	cin >> a >> b;

	int reuse = 0;
	int candles = a;

	while (candles >= b) {
		int current = candles / b;
		reuse += current;
		candles = current + (candles % b);
	}

	cout << a + reuse << endl;

	return 0;
}

// 6 3
// candles = 6
// curr = 2
// reuse = 2
// candles = 2