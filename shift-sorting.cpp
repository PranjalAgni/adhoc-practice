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

		int N = str.length();

		long long left = 0;
		while (str[left] == '0' && left < N) left += 1;
		long long right = left;
		long long answer = 0;
		while (right < N) {
			if (str[right] == '0') {
				answer += right - left + 1;
				left += 1;
			}

			right += 1;
		}

		cout << answer << endl;
	}
	return 0;
}