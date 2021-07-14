#include <bits/stdc++.h>
using namespace std;

class EarliestUnique {
public:
	deque<int> dq;
	unordered_map<int, int> seen;
	EarliestUnique(vector<int>& nums) {
		dq = deque<int>();
		seen = unordered_map<int, int>();
		for (int num : nums) {
			seen[num] += 1;
			if (seen[num] == 1) dq.push_back(num);
		}
	}

	void add(int num) {
		seen[num] += 1;
		if (seen[num] == 1) {
			dq.push_back(num);
		}
	}

	int earliestUnique() {
		while (!dq.empty() && seen[dq.front()] > 1) dq.pop_front();
		return dq.empty() ? -1 : dq.front();
	}
};

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	EarliestUnique earliestUnique = new EarliestUnique({1, 2, 3});
	earliestUnique.add(2);
	cout << earliestUnique.earliestUnique() << endl;
	earliestUnique.add(1);
	cout << earliestUnique.earliestUnique() << endl;
	return 0;
}