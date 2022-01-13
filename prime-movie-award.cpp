#include <bits/stdc++.h>
using namespace std;

int minimumGroups(vector<int> awards, int k) {
	sort(awards.begin(), awards.end());
	int N = awards.size();
	int minGroupsCount = 0;

	for (int idx = 0; idx < N; idx++) {
		int nextIdx = idx + 1;
		while (nextIdx < N && awards[nextIdx] - awards[idx] <= k) {
			nextIdx += 1;
		}

		minGroupsCount += 1;
		idx = nextIdx - 1;
	}

	return minGroupsCount;
}
int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N;
	cin >> N;

	vector<int> awards(N);
	for (int idx = 0; idx < N; idx++) cin >> awards[idx];
	int k;
	cin >> k;

	cout << minimumGroups(awards, k) << endl;
	return 0;
}
