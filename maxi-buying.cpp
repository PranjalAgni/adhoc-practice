#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N;

	cin >> N;

	int tax = N * 1.08;

	if (tax < 206) {
		cout << "Yay!" << endl;
	} else if (tax == 206) {
		cout << "so-so" << endl;
	} else {
		cout << ":(" << endl;
	}
	return 0;
}