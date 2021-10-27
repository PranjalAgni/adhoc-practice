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
	set<pair<int, int>> window;
	// 1. If length is odd
	// get middle element from set if
	// else get the lower middle element from the set
	// 2. remove the pos index element from set
	// 3. add the median to answer list

	int medianElementIndex = (K % 2 == 0) ? K / 2 - 1 : K / 2;

	while (pos < N) {
		pair<int, int> p = make_pair(nums[pos], pos);
		window.insert(p);
		cout << window.size() << endl;
		int windowSize = window.size();
		if (windowSize == K) {
			int currentIndex = 0;

			for (const auto& iterator : window) {
				if (medianElementIndex == currentIndex) {
					medianOfWindow.push_back(iterator.first);
					break;
				}
				currentIndex += 1;
			}

			// remove the element from set
			window.erase({nums[pos - K], K});
		}
		pos += 1;
	}

	for (int median : medianOfWindow) cout << median << " ";
	return 0;
}