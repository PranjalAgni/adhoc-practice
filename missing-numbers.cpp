#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	long long N;
	cin >> N;

	long long sum = 0;
	for (int idx = 0; idx < N - 1; idx++) {
		int elt;
		cin >> elt;
		sum += elt;
	}

	long long sumOfNElements = (N * (N + 1)) / 2;
	cout << (sumOfNElements  - sum) << endl;
	return 0;
}

