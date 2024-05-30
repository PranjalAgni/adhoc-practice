#include <bits/stdc++.h>
using namespace std;

bool dfs(int vertex, int parent, unordered_map<int, bool>& visitedMap, unordered_map<int, vector<int>>& adjList) {
	if (visitedMap[vertex]) return true;
	visitedMap[vertex] = true;
	vector<int> neighbours = adjList[vertex];
	for (int& neighbour : neighbours) {
		if (neighbour == parent) continue;
		if (visitedMap[neighbour]) return true;
		bool isCycle = dfs(neighbour, vertex, visitedMap, adjList);
		if (isCycle) return true;
	}

	return false;
}

bool detectCycle(int& nodes, unordered_map<int, vector<int>>& adjList) {
	unordered_map<int, bool> visitedMap;
	return dfs(1, -1, visitedMap, adjList);
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
		adjList[v].push_back(u);
	}

	bool isCycle = detectCycle(nodes, adjList);

	if (isCycle) {
		cout << "Cycle is there" << endl;
	} else {
		cout << "No cycle" << endl;
	}
	return 0;
}