#include <bits/stdc++.h>
using namespace std;

struct NodeInfo {
	vector<char> path;
	int row;
	int col;
};

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

	int N, M;
	cin >> N >> M;
	vector<vector<char>> graph(N, vector<char>(M));
	queue<NodeInfo> nodeQueue;

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < M; col++) {
			char ch;
			cin >> ch;
			graph[row][col] = ch;
			if (ch == 'A') {
				NodeInfo nodeInfo = {{}, row, col};
				nodeQueue.push(nodeInfo);
			}
		}
	}

	string finalPath = "";
	bool isReached = false;

	while (!nodeQueue.empty()) {
		NodeInfo nodeInfo = nodeQueue.front();
		nodeQueue.pop();
		vector<pair<int, pair<int, char>>> directions = {{0, {1, 'R'}}, {0, { -1, 'L'}}, {1, {0, 'D'}}, { -1, {0, 'U'}}};

		for (pair<int, pair<int, char>> dir : directions) {
			int newRow = nodeInfo.row + dir.first;
			int newCol = nodeInfo.col + dir.second.first;

			if (isValid(N, M, newRow, newCol)) {
				char ch = graph[newRow][newCol];
				if (ch == 'B') {
					nodeInfo.path.push_back(dir.second.second);
					finalPath = string(nodeInfo.path.begin(), nodeInfo.path.end());
					isReached = true;
					break;
				} else if (ch == '.') {
					graph[newRow][newCol] = '#';
					vector<char> currentPath = nodeInfo.path;
					currentPath.push_back(dir.second.second);
					NodeInfo nextNodeInfo = {currentPath, newRow, newCol};
					nodeQueue.push(nextNodeInfo);
				}
			}
		}

		if (isReached) break;
	}

	if (isReached) {
		cout << "YES" << endl;
		cout << finalPath.length() << endl;
		cout << finalPath << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}