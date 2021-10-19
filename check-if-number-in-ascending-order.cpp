#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	bool isDigit(char ch) {
		return ch >= '0' && ch <= '9';
	}


	bool areNumbersAscending(string s) {
		int N = s.length();
		int current = -1;
		int previous = -1;

		for (int idx = 0; idx < N; idx++) {
			char ch = s[idx];
			if (isDigit(ch)) {
				if (current == -1) current = 0;
				int digit = ch - '0';
				current = current * 10 + digit;
			} else {
				if (current == -1) continue;
				if (previous == -1) {
					previous = current;
					current = -1;
					continue;
				}
				if (previous >= current) return false;
				previous = current;
				current = -1;
			}
		}

		if (current != -1 && previous >= current) return false;

		return true;
	}
};


int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	Solution solution;
	bool answer = solution.areNumbersAscending("1 box has 3 blue 4 red 6 green and 12 yellow marbles");
	cout << answer << endl;

	return 0;
}