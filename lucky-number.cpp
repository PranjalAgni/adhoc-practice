#include <bits/stdc++.h>
using namespace std;


int getLuckiness(int num) {
	int largest = -1, smallest = 10, digit;
	while (num > 0) {
		digit = num % 10;
		largest = max(largest, digit);
		smallest = min(smallest, digit);
		num /= 10;
	}
	return largest - smallest;
}


int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	// vector<int> luckiness(1000 + 1);

	// for (int i = 1; i <= 1000; i++) {
	// 	luckiness[i] = getLuckiness(i);
	// }

	int T;
	cin >> T;

	while (T-- > 0) {
		int L, R;
		cin >> L >> R;

		int answer = L;
		int luckiness = INT_MIN;
		for (int idx = L; idx <= R; idx++) {
			string digits = to_string(idx);
			int max_dig = *max_element(digits.begin(), digits.end());
			int min_dig = *min_element(digits.begin(), digits.end());
			if (max_dig - min_dig >= luckiness) {
				luckiness = max_dig - min_dig;
				answer = idx;
			}

		}

		cout << answer;
		if (T > 0) {
			cout << endl;
		}
	}

	return 0;
}

// Rent  Room    1m  6d   24d
// 16000 pranjal 534 3204 12816(6408*2)
// 15000 sandesh 500 3000 12000(6000*2)
// 14500 ?       484 2904 11616



