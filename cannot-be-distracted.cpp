#include <bits/stdc++.h>
using namespace std;

const string YES = "YES";
const string NO = "NO";

string solve(string tasksOrder, int N) {
	unordered_map<int, int> lastSeenMap;
	for (int idx = 0; idx < N; idx++) {
		char ch = tasksOrder[idx];
		if (lastSeenMap.find(ch) != lastSeenMap.end()) {
			if (idx - lastSeenMap[ch] > 1) return NO;
		}

		lastSeenMap[ch] = idx;
	}

	return YES;
}


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
		string tasksOrder;
		cin >> tasksOrder;

		cout << solve(tasksOrder, N) << endl;
	}

	return 0;
}