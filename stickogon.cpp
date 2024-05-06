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
		int N;
		cin >> N;
		vector<int> sides(N);
		for (int idx = 0; idx < N; idx++) {
			cin >> sides[idx];
		}

		if (N < 3) {
			cout << 0 << endl;
		} else {
			int answer = 0;
			unordered_map<int, int> freqMap;
			for (int& side : sides) {
				freqMap[side] += 1;
			}

			for (auto const& itr : freqMap) {
				int val = itr.second;
				answer += val / 3;
			}

			cout << answer << endl;
		}
	}

	return 0;
}

/**
	About regular Polygons:


To count the number of regular polygons you can make using
𝑛
n straight lines, you need to consider a few things:

Minimum number of sides: A regular polygon must have at least 3 sides.
Maximum number of sides: The maximum number of sides a polygon can have with


Conditions for a regular polygon: All sides of the polygon must have equal length, and all angles must be equal.

*/