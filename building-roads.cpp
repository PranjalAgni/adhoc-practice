#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map<int, vector<int>>& adjList, int node, int parent, vector<int>& visited) {
	if (visited[node]) return;
	visited[node] = 1;
	for (int& neighbour : adjList[node]) {
		if (neighbour == parent) continue;
		dfs(adjList, neighbour, node, visited);
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


	vector<int> visited(n + 1, 0);

	vector<int> disconnectedCities;

	for (int v = 1; v <= n; v++) {
		if (!visited[v]) {
			dfs(adjList, v, -1, visited);
			disconnectedCities.push_back(v);
		}
	}

	int N = disconnectedCities.size();
	cout << N - 1 << endl;
	if (N > 1) {
		for (int idx = 1; idx < N; idx++) {
			cout << disconnectedCities[idx - 1] << " " << disconnectedCities[idx] << endl;
		}
	}

	return 0;
}