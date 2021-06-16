#include <bits/stdc++.h>
using namespace std;


long long getSquare(long long val) {
	return val * val;
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	long long A, B, C;
	cin >> A >> B >> C;

	if (getSquare(A) + getSquare(B) < getSquare(C)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}