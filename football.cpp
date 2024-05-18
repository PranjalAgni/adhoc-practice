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
	unordered_map<string, int> freqMap;
	int maxScore = 0;
	string answer = "";
	while (N-- > 0) {
		string team;
		cin >> team;
		freqMap[team] += 1;
		if (freqMap[team] > maxScore) {
			maxScore = freqMap[team];
			answer = team;
		}
	}

	cout << answer << endl;

	return 0;
}