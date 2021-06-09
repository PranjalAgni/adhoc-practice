#include <bits/stdc++.h>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	string S;
	cin >> S;

	reverse(S.begin(), S.end());

	for (int idx = 0; idx < S.length(); idx++) {
		if (S[idx] == '6') S[idx] = '9';
		else if (S[idx] == '9') S[idx] = '6';
	}

	cout << S << endl;
	return 0;
}