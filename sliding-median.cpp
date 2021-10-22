#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N, K;
	cin >> N >> K;

	vector<int> elements(N);
	for (int idx = 0; idx < N; idx++) cin >> elements[idx];

	int pos = 0;
	vector<int> nums;
	vector<int> medianOfWindow;

	while (pos < N) {
		nums.push_back(elements[pos]);
		int windowSize = nums.size();
		if (windowSize == K) {
			vector<int> sortedNums = nums;
			sort(sortedNums.begin(), sortedNums.end());
			int currentMedian = (K % 2 == 0) ? sortedNums[(K / 2) - 1] : sortedNums[K / 2];
			medianOfWindow.push_back(currentMedian);
			nums.erase(nums.begin());
		}
		pos += 1;
	}

	for (int median : medianOfWindow) cout << median << " ";
	return 0;
}