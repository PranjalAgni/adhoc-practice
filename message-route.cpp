#include <bits/stdc++.h>
using namespace std;

int bfs(unordered_map<int, vector<int>>& adjList, int n) {
	vector<int> visited(n + 1, 0);

	queue<int> q;
	q.push(1);
	int distance = 0;

	while (!q.empty()) {
		int node = q.front();
		visited[node] = 1;
		q.pop();
		distance += 1;
		if (node == n) {
			break;
		}
		for (int& neighbour : adjList[node]) {
			if (visited[neighbour]) continue;
			q.push(neighbour);
		}
	}

	return distance;
}

void dfs(int& N, unordered_map<int, vector<int>>& adjList, int node, int parent, vector<int>& visited, int& answer) {
	if (visited[node]) return;
	visited[node] = 1;
	answer += 1;
	if (node == N) return;
	for (int& neighbour : adjList[node]) {
		if (neighbour == parent) continue;
		dfs(N, adjList, neighbour, node, visited, answer);
	}
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

	unordered_map<int, vector<int>> adjList;

	while (m-- > 0) {
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	// cout << bfs(adjList, n) << endl;
	vector<int> visited(n + 1, 0);
	int answer = 0;
	dfs(n, adjList, 1, -1, visited, answer);
	cout << answer << endl;
	return 0;
}