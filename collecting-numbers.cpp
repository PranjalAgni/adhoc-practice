#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> getElementToPositionMap(vector<int>& nums) {
	int N = nums.size();
	unordered_map<int, int> elementToPos;
	elementToPos[0] = 0;

	for (int idx = 0; idx < N; idx++) {
		elementToPos[nums[idx]] = idx;
	}

	return elementToPos;
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
	vector<int> nums(N);

	for (int idx = 0; idx < N; idx++) {
		cin >> nums[idx];
	}

	unordered_map<int, int> elementToPos = getElementToPositionMap(nums);

	int answer = 1;
	for (int elt = 1; elt <= N; elt++) {
		if (elementToPos[elt] < elementToPos[elt - 1]) answer += 1;
	}

	cout << answer << endl;
	return 0;
}