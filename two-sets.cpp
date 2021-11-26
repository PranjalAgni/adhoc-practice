#include <bits/stdc++.h>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	unsigned long long N;
	cin >> N;

	unsigned long long sumOfNElements = (N * (N + 1)) / 2;

	if (sumOfNElements % 2 != 0) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		unsigned long long target = sumOfNElements / 2;
		unsigned  long long sum = 0;
		unordered_map<unsigned long long, unsigned long long> seenElements;
		unsigned  long long current = N;
		unsigned long long count = 0;

		while (sum < target) {
			count += 1;
			sum += current;
			seenElements[current] = 1;
			current -= 1;
		}

		if (sum > target) {
			seenElements[current + 1] = 0;
			sum -= (current + 1);
			unsigned long long diff = target - sum;
			seenElements[diff] = 1;
		}

		cout << count << endl;
		for (unsigned long long elt = 1; elt <= N; elt++) {
			if (seenElements[elt] == 1) cout << elt << " ";
		}

		cout << "\n" <<  N - count << endl;
		for (unsigned long long elt = 1; elt <= N; elt++) {
			if (seenElements[elt] == 0) cout << elt << " ";
		}

		cout << endl;
	}

	return 0;
}