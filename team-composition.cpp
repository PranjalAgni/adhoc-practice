// https://codeforces.com/contest/1611/problem/B

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
		int programmers, mathematician;
		cin >> programmers >> mathematician;

		int totalPeople = programmers + mathematician;

		if (totalPeople < 4 || programmers == 0 || mathematician == 0) cout << 0 << endl;
		else if (programmers == mathematician) cout << (totalPeople) / 4 << endl;
		else {
			int teams = totalPeople / 4;
			teams = min({teams, programmers, mathematician});
			cout << teams << endl;
		}

	}
	return 0;
}