#include <bits/stdc++.h>
using namespace std;

// nice bipartite graph problem
bool dfs(unordered_map<int, vector<int>>& adjList, int node, int parent, int teamNum, vector<int>& visited, vector<int>& team) {
	if (visited[node]) {
		if (team[node] != teamNum) return false;
		return true;
	}

	visited[node] = true;
	team[node] = teamNum;
	for (int& neighbour : adjList[node]) {
		if (node == neighbour) continue;
		int oppositeTeam = (teamNum == 1) ? 2 : 1;
		bool isPossible = dfs(adjList, neighbour, node, oppositeTeam, visited, team);
		if (!isPossible) return false;
	}

	return true;
}
int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int n, e;
	cin >> n >> e;

	unordered_map<int, vector<int>> adjList;

	while (e-- > 0) {
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	vector<int> visited(n + 1, 0);
	vector<int> team(n + 1);

	bool isPossible = true;
	for (int node = 1; node <= n; node++) {
		if (!visited[node]) {
			isPossible = dfs(adjList, node, -1, 1, visited, team);
			if (!isPossible) {
				break;
			}
		}
	}

	if (isPossible) {
		for (int node = 1; node <= n; node++) {
			cout << team[node] << " ";
		}
		cout << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}

	return 0;
}