#include <bits/stdc++.h>
using namespace std;


bool isValid(int& N, int& M, int row, int col) {
	return (row >= 0 && row < N && col >= 0 && col < M);
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	clock_t startTime = clock();

	int N, M;
	cin >> N >> M;
	vector<vector<char>> graph(N, vector<char>(M));
	vector<vector<bool>> visited(N, vector<bool>(M, false));

	queue<pair<int, int>> nodeQueue;
	pair<int, int> begin, end;
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			char ch;
			cin >> ch;
			graph[row][col] = ch;
			if (ch == 'A') {
				begin = {row, col};
				nodeQueue.push(begin);
				visited[row][col] = true;
			} else if (ch == 'B') {
				end = {row, col};
			} else if (ch == '#') {
				visited[row][col] = true;
			}
		}
	}

	bool isReached = false;
	map<pair<int, int>, char> parent;
	map<char, pair<int, int>> directionsMap = {{'R', {0, 1}}, {'U', { -1, 0}}, {'L', {0, -1}}, {'D', {1, 0}}};
	while (!nodeQueue.empty()) {
		pair<int, int> currentNode = nodeQueue.front();
		nodeQueue.pop();


		for (const auto &[direction, stepValue] : directionsMap) {
			int newRow = currentNode.first + stepValue.first;
			int newCol = currentNode.second + stepValue.second;

			if (isValid(N, M, newRow, newCol) && !visited[newRow][newCol]) {
				char ch = graph[newRow][newCol];
				visited[newRow][newCol] = true;
				pair<int, int> nextNodeInfo = {newRow, newCol};
				parent[nextNodeInfo] = direction;
				if (ch == 'B') {
					isReached = true;
					break;
				} else if (ch == '.') {
					nodeQueue.push(nextNodeInfo);
				}
			}
		}

		if (isReached) break;
	}

	if (isReached) {
		cout << "YES" << endl;
		vector<char> steps;
		while (end != begin) {
			char step = parent[ {end.first, end.second}];
			steps.push_back(step);
			pair<int, int> direction = directionsMap[step];
			end = make_pair(end.first - direction.first, end.second - direction.second);
		}
		cout << steps.size() << endl;
		for (int idx = steps.size() - 1; idx >= 0; idx--) cout << steps[idx];
	} else {
		cout << "NO" << endl;
	}

	clock_t endTime = clock();
	double elapsed_secs = double(endTime - startTime) / CLOCKS_PER_SEC;

	cout << "\nClock time = " << elapsed_secs << "sec" << endl;
	return 0;
}