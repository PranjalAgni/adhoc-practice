#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	long long int N;

	cin >> N;

	while (N != 1) {
		cout << N << " ";
		if (N % 2 == 0) N = N / 2;
		else N = (N * 3) + 1;
	}

	cout << 1 << endl;

	return 0;
}