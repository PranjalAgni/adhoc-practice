#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N;
	cin >> N;

	int answer = 1;
	while (N-- > 0) {
		answer = (answer * 2) % MOD;
	}

	cout << answer << endl;

	return 0;
}