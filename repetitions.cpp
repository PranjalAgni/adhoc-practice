#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	string dna;
	cin >> dna;
	int N = dna.length();

	char ch = dna[0];
	int currentLongest = 1;
	int answer = 1;
	for (int idx = 1; idx < N; idx++) {
		if (dna[idx] == ch) {
			currentLongest += 1;
		} else {
			answer = max(answer, currentLongest);
			currentLongest = 1;
		}

		ch = dna[idx];
	}

	answer = max(answer, currentLongest);
	cout << answer << endl;
	return 0;
}