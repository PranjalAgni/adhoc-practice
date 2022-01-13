#include <bits/stdc++.h>
using namespace std;


int sumOfAllProcess(vector<int> process) {
	int sum = 0;
	for (int p : process) sum += p;
	return sum;
}
int minimizeMemory(vector<int> process, int m) {
	int maxContigousProcess = 0;

	int N = process.size();
	int currentSum = 0;
	for (int idx = 0; idx < N; idx++) {
		if (idx < m) {
			currentSum += process[idx];
		} else {
			maxContigousProcess = max(maxContigousProcess, currentSum);
			currentSum = currentSum - process[idx - m] + process[idx];
		}
	}

	maxContigousProcess = max(maxContigousProcess, currentSum);
	return sumOfAllProcess(process) - maxContigousProcess;
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
	vector<int> process(N);

	for (int idx = 0; idx < N; idx++) {
		cin >> process[idx];
	}

	int m;
	cin >> m;

	cout << minimizeMemory(process, m);

	return 0;
}