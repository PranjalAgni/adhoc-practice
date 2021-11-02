#include <bits/stdc++.h>
using namespace std;

void removeElementFromSet(set<pair<int, int>>& leftSet, set<pair<int, int>>& rightSet, int elt, int targetIdx) {
	set<pair<int, int>>::iterator it = leftSet.find(make_pair(elt, targetIdx));
	if (it != leftSet.end()) {
		leftSet.erase(it);
		return;
	}
	it = rightSet.find(make_pair(elt, targetIdx));
	rightSet.erase(it);
	return;
}

void balanceSet(set<pair<int, int>>& leftSet, set<pair<int, int>>& rightSet, int& L, int& R) {
	while ((int)leftSet.size() > L) {
		set<pair<int, int>>::iterator it = leftSet.end();
		--it;
		leftSet.erase(it);
		rightSet.insert(make_pair(it->first, it->second));
	}


	while ((int)rightSet.size() > R) {
		set<pair<int, int>>::iterator it = rightSet.begin();
		leftSet.insert(make_pair(it->first, it->second));
		rightSet.erase(it);
	}

	return;
}


int decideWhereToInsert(set<pair<int, int>>& leftSet, set<pair<int, int>>& rightSet, int elt) {
	set<pair<int, int>>::iterator it;
	if (!leftSet.empty()) {
		it = leftSet.end();
		--it;
		if (it->first >= elt) return 1;
	}

	return 2;
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N, K;
	cin >> N >> K;

	vector<int> nums(N);

	for (int idx = 0; idx < N; idx++) {
		cin >> nums[idx];
	}

	set<pair<int, int>> leftSet, rightSet;
	set<pair<int, int>>::iterator it;
	int L = (K % 2 == 0) ?  (K / 2) - 1 : K / 2;
	int R = K - L;

	for (int idx = 0; idx < N; idx++) {
		int setIdToInsert = decideWhereToInsert(leftSet, rightSet, nums[idx]);
		if (setIdToInsert == 1) leftSet.insert(make_pair(nums[idx], idx));
		else rightSet.insert(make_pair(nums[idx], idx));

		balanceSet(leftSet, rightSet, L, R);
		if (idx >= K - 1) {
			it = rightSet.begin();
			cout << it->first << " ";
			removeElementFromSet(leftSet, rightSet, nums[idx - (K - 1)], idx - (K - 1));
		}

	}

	cout << endl;
	return 0;
}