#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	string program;
	cin >> program;
	bool isCorrect = false;

	for (char& ch : program) {
		if (ch == 'H' || ch == 'Q' || ch == '9') {
			isCorrect = true;
			break;
		}
	}

	if (isCorrect) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}