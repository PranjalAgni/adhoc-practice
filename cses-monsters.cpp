#include <bits/stdc++.h>
using namespace std;

bool isBoundary(int row, int col, int rows, int cols) {
	return (row == 0 || row == rows - 1 || col == 0 || col == cols - 1);
}

bool isValidDirection(int x, int y, int&n, int& m) {
	return (x >= 0 && x < n && y >= 0 && y < m);
}

bool canMove(vector<vector<char>>& graph, int x, int y) {
	return graph[x][y] != '#';
}

char getOppositeDirection(char d) {
	if (d == 'L') return 'R';
	else if (d == 'R') return 'L';
	else if (d == 'U') return 'D';
	else if (d == 'D') return 'U';
}
pair<bool, string> bfs(int row, int col, vector<vector<char>>& graph, vector<vector<int>>& visited) {
	queue<pair<int, int>> q;
	q.push(make_pair(row, col));
	queue<string> pathQ;
	pathQ.push("");

	int n = graph.size();
	int m = graph[0].size();

	vector<vector<int>> directions = {{1, 0}, { -1, 0}, {0 , 1}, {0, -1}};
	vector<char> directionsSymbols = {'D', 'U', 'R', 'L'};
	vector<char> answer;
	bool isFound = false;
	string validPath;
	int minDistanceToReachM = INT_MAX;
	int minDistanceToReachA = INT_MAX;
	while (!q.empty()) {
		pair<int, int> current = q.front();
		string currentPath = pathQ.front();
		int len = currentPath.length();
		q.pop();
		pathQ.pop();
		int x = current.first;
		int y = current.second;
		visited[x][y] = 1;
		if (graph[x][y] == 'M') {
			minDistanceToReachM = min(minDistanceToReachM, len);
			if (minDistanceToReachM <= 1) break;
			continue;
		} else if (graph[x][y] == 'A') {
			if (len < minDistanceToReachA) {
				validPath = currentPath;
				minDistanceToReachA = len;
			}
			isFound = true;
			continue;
		}
		for (int idx = 0; idx < 4; idx++) {
			vector<int> dir = directions[idx];
			int new_x = x + dir[0];
			int new_y = y + dir[1];
			if (isValidDirection(new_x, new_y, n, m) && canMove(graph, new_x, new_y)) {
				if (visited[new_x][new_y] == 0) {
					q.push(make_pair(new_x, new_y));
					pathQ.push(currentPath + getOppositeDirection(directionsSymbols[idx]));
				}
			}
		}
	}


	if (!isFound || minDistanceToReachM <= minDistanceToReachA) return make_pair(false, "");
	return make_pair(true, validPath);
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	vector<vector<char>> graph(n, vector<char>(m));
	vector<vector<int>> boundaryNodes;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < m; col++) {
			cin >> graph[row][col];
			if (isBoundary(row, col, n, m) && (graph[row][col] == '.' || graph[row][col] == 'A')) {
				boundaryNodes.push_back({row, col});
			}
		}
	}

	bool isPossible = false;
	string answer;
	// vector<vector<int>> visited(n, vector<int>(m, 0));

	for (vector<int>& bnodes : boundaryNodes) {
		vector<vector<int>> visited(n, vector<int>(m, 0));
		int x = bnodes[0];
		int y = bnodes[1];
		if (visited[x][y] == 0) {
			pair<bool, string> result = bfs(x, y, graph, visited);
			if (result.first) {
				answer = result.second;
				isPossible = true;
				break;
			}
		}
	}

	if (isPossible) {
		cout << "YES" << endl;
		int steps = answer.length();
		cout << steps << endl;
		for (int idx = steps - 1; idx >= 0; idx--) {
			cout << answer[idx];
		}
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}