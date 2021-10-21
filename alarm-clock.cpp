#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int T;
	cin >> T;

	while (T-- > 0) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;

		if (b >= a) cout << b << endl;
		else if (d >= c) cout << -1 << endl;
		else {
			long long sleepRemaning = a - b;
			long long sleepTime = c - d;
			long long alarmReset = sleepRemaning / sleepTime;
			if (sleepRemaning % sleepTime != 0) alarmReset += 1;
			cout << b + (c * alarmReset) << endl;
		}
	}

	return 0;
}