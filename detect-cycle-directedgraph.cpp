#include <bits/stdc++.h>
using namespace std;

bool dfs(unordered_map<int, vector<int>>& adjList, int node, int parent, vector<int>& visited, vector<int>& path) {
	if (visited[node] && path[node]) return true;
	visited[node] = 1;
	path[node] = 1;
	for (int& neighbour : adjList[node]) {
		bool isCycle = dfs(adjList, neighbour, node, visited, path);
		if (isCycle) return true;
	}

	path[node] = 0;
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int nodes, edges;
	cin >> nodes >> edges;

	int T = edges;
	unordered_map<int, vector<int>> adjList;

	while (T-- > 0) {
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
	}

	vector<int> visited(nodes + 1, 0);
	vector<int> path(nodes + 1, 0);


	bool isCycle = dfs(adjList, 1, -1, visited, path);
	if (isCycle) {
		cout << "Cycle found" << endl;
	} else {
		cout << "No cycle" << endl;
	}


	return 0;
}