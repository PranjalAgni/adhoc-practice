#include <bits/stdc++.h>
using namespace std;


void dfsColoring(int src, int par, unordered_map<int, vector<int>>& adjList, vector<int>& color, vector<int>& parent, vector<vector<int>>& cycles) {
	if (color[src] == 2) {
		// this node is completely processed
		// we should return from here
		return;
	}

	if (color[src] == 1) {
		// this node is marked as "in processing"
		// this means cycle is detected as we came back to it from some other node
		vector<int> cycle;
		int curr = par;
		cycle.push_back(curr);
		while (curr != src) {
			curr = parent[curr];
			cycle.push_back(curr);
		}

		cycles.push_back(cycle);
		return;
	}

	parent[src] = par;
	color[src] = 1;

	for (int& neighbour : adjList[src]) {
		if (neighbour == par) continue;
		dfsColoring(neighbour, src, adjList, color, parent, cycles);
	}

	// this is completely processed now
	color[src] = 2;
	return;
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


	vector<int> color(n, 0);
	vector<int> parent(n);
	vector<vector<int>> cycles;
	dfsColoring(0, -1, adjList, color, parent, cycles);

	// printing all the cycles
	for (vector<int>& cycle : cycles) {
		for (int& n : cycle) {
			cout << n << " ";
		}
		cout << endl;
	}
	return 0;
}