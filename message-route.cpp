#include <bits/stdc++.h>
using namespace std;

struct TraversalData {
	int node;
	int parent;
	int distance;
};

void bfs(unordered_map<int, vector<int>>& adjList, int n, int src, int target) {
	vector<int> distance(n + 1, INT_MAX);
	vector<int> parent(n + 1);
	queue<TraversalData> q;
	q.push({src, -1, 1});


	while (!q.empty()) {
		TraversalData current = q.front();
		q.pop();
		if (current.distance < distance[current.node]) {
			distance[current.node] = current.distance;
			parent[current.node] = current.parent;

			for (int& neighbour : adjList[current.node]) {
				q.push({neighbour, current.node, current.distance + 1});
			}
		}
	}

	if (distance[target] == INT_MAX) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		cout << distance[target] << endl;
		vector<int> path;

		while (parent[target] != -1) {
			path.push_back(target);
			target = parent[target];
		}

		path.push_back(src);

		for (int idx = path.size() - 1; idx >= 0; idx--) {
			cout << path[idx] << " ";
		}

		cout << endl;
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

	bfs(adjList, n, 1, n);

	return 0;
}