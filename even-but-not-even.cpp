// https://codeforces.com/problemset/problem/1291/A
#include <bits/stdc++.h>
using namespace std;

// Time: O(N) | Space: O(1)
int getStringSum(string& str) {
	int sum = 0;
	for (char ch : str) {
		int digit = ch - '0';
		sum += digit;
	}

	return sum;
}

// Time: O(N) | Space: O(N)
string getOddNum(string& str, int N) {
	int right = N - 1;
	int digit = str[right] - '0';
	while (right >= 0 && digit % 2 == 0) {
		right -= 1;
		digit = str[right] - '0';
	}

	if (right == -1) return "-1";
	return str.substr(0, right + 1);
}

// Time: O(N) | Space: O(N)
string makeSumEven(string& str) {
	int N = str.length();
	int oddPos = 0;
	int idx = N - 2;
	bool isPossible = false;
	while (idx >= 0) {
		int digit = str[idx] - '0';
		if (digit % 2 != 0) {
			isPossible = true;
			oddPos = idx;
			break;
		}
		idx -= 1;
	}

	if (!isPossible) return "-1";
	return str.substr(0, oddPos) + str.substr(oddPos + 1, N - (oddPos + 1));
}

// Time: O(N) | Space: O(N)
string removeTrailingZeroes(string str) {
	if (str == "-1") return str;
	int N = str.length();
	int pos = 0;
	while (pos < N && str[pos] == '0') {
		pos += 1;
	}

	if (pos == N) return "-1";
	return str.substr(pos, N - pos);
}

// Time: O(N) | Space: O(N)
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
		int N;
		cin >> N;
		string num;
		cin >> num;

		string oddNum = getOddNum(num, N);
		if (oddNum == "-1") cout << oddNum << endl;
		else {
			int sum = getStringSum(oddNum);
			if (sum % 2 == 0) cout << oddNum << endl;
			else {
				cout << removeTrailingZeroes(makeSumEven(oddNum)) << endl;
			}
		}
	}
	return 0;
}