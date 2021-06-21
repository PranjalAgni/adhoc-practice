#include <bits/stdc++.h>
using namespace std;

bool comparatorFn(vector<int> routeA, vector<int> routeB) {
	return routeA[1] < routeB[1];
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N, M, maxCost;
	cin >> N >> M >> maxCost;

	vector<vector<int>> forwardList(N);
	vector<vector<int>> returnList(M);

	for (int idx = 0; idx < N; idx++) {
		int id, cost;
		cin >> id >> cost;
		forwardList[idx] = {id, cost};
	}

	for (int idx = 0; idx < M; idx++) {
		int id, cost;
		cin >> id >> cost;
		returnList[idx] = {id, cost};
	}

	sort(forwardList.begin(), forwardList.end(), comparatorFn);
	sort(returnList.begin(), returnList.end(), comparatorFn);

	vector<vector<int>> optimizedList;
	int low = 0;
	int high = M - 1;

	int currMax = INT_MIN;

	while (low < N && high >= 0) {
		int currCost = forwardList[low][1] + returnList[high][1];
		if (currCost <= maxCost) {
			if (currCost > currMax) {
				optimizedList.clear();
				currMax = currCost;
			}
			if (currMax == currCost) {
				optimizedList.push_back({forwardList[low][0], returnList[high][0]});
			}
			low += 1;
		} else {
			high -= 1;
		}
	}

	for (vector<int> route : optimizedList) {
		cout << route[0] << " " << route[1] << endl;
	}

	return 0;
}