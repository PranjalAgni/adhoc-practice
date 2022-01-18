#include <bits/stdc++.h>
using namespace std;

void solve(vector<int>& path, int& maxStep, long& maximumSum, int index, long currentSum) {
	if (index == path.size() - 1) {
		maximumSum = max(maximumSum, currentSum);
	} else {
		for (int step = 1; step <= maxStep; step++) {
			int idx = index + step;
			if (idx < path.size()) {
				solve(path, maxStep, maximumSum, idx, currentSum + path[idx]);
			}
		}
	}
}

long journey(vector<int> path, int maxStep) {
	long maximumSum = 0;
	solve(path, maxStep, maximumSum, -1, 0);
	return  maximumSum;
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
	vector<int> path(N);

	for (int idx = 0; idx < N; idx++) {
		cin >> path[idx];
	}

	int maxStep;
	cin >> maxStep;
	cout << journey(path, maxStep) << endl;
	return 0;
}