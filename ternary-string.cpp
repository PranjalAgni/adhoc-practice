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
		string str;
		cin >> str;
		int len = str.length();

		// Time: O(N) | Space: O(1)
		vector<int> hashMap(3, 0);
		int answer = len + 1;
		int low = 0;
		for (int idx = 0; idx < len; idx++) {
			int digit = str[idx] - '1';
			hashMap[digit] += 1;

			while (hashMap[str[low] - '1'] > 1) {
				hashMap[str[low] - '1'] -= 1;
				low += 1;
			}

			if (hashMap[0] && hashMap[1] && hashMap[2]) {
				answer = min(answer, idx - low + 1);
				if (answer == 3) break;
			}

		}

		if (answer == len + 1) answer = 0;
		cout << answer << endl;
	}


	return 0;
}