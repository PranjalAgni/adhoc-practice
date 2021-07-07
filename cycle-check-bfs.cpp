#include <bits/stdc++.h>
using namespace std;

bool bfs(int vertex, vector<vector<int>>& adjList, unordered_map<int, bool>& visitedMap) {
	queue<pair<int, int>> q;
	q.push({vertex, -1});

	while (!q.empty()) {
		pair<int, int> current = q.front();
		q.pop();

		nodeValue = current.first;
		int parentValue = current.second;
		visitedMap[nodeValue] = true;

		for (int neighbour : adjList[nodeValue]) {
			if (visitedMap[neighbour] && parentValue != neighbour) return true;
			if (visitedMap[neighbour]) continue;
			q.push({neighbour, nodeValue});
		}
	}

	return false;

}

bool checkCycleWithBFS(vector<vector<int>>& adjList) {
	int V = adjList.size();
	unordered_map<int, bool> visitedMap;

	for (int v = 0; v < V; v++) {
		if (!visitedMap[v]) {
			bool isCycle = bfs(v, adjList, visitedMap);
			if (isCycle) return true;
		}
	}

	return false;
}


int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int V;

	cin >> V;

	vector<vector<int>> adjList(V, vector<int>());

	for (int v = 0; v < V; v++) {
		int E;
		cin >> E;
		vector<int> neighbours(E);
		for (int e = 0; e < E; e++) {
			cin >> neighbours[e];
		}

		adjList[v] = neighbours;
	}


	cout << checkCycleWithBFS(adjList) << endl;

	return 0;
}