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
		int n, a, b;
		cin >> n >> a >> b;

		int doubleAtRegularPrice = a * 2;
		if (doubleAtRegularPrice < b) {
			cout << n * a << endl;
		} else {
			int atPromotionPrice = n / 2;
			int remaining = n % 2;
			cout << atPromotionPrice * b + remaining * a << endl;
		}
	}
	return 0;
}