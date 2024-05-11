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
		int n, a, b;
		cin >> n >> a >> b;
		string answer = "";
		for (int idx = 0; idx < n; idx++) {
			char ch = 'a' + (idx % b);
			answer += ch;
		}

		cout << answer << endl;


	}
	return 0;
}
