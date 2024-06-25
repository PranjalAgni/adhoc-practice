#include <bits/stdc++.h>
using namespace std;


void dfsColoring(int src, int par, unordered_map<int, vector<int>>& adjList, vector<int>& color, vector<int>& parent, vector<vector<int>>& cycles) {
	if (color[src] == 2 || cycles.size() > 0) {
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

		cycle.push_back(par);
		if (cycle.size() >= 4) {
			cycles.push_back(cycle);
		}
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


	vector<int> color(n + 1, 0);
	vector<int> parent(n + 1);
	vector<vector<int>> cycles;

	for (int v = 1; v <= n; v++) {
		if (color[v] != 2) {
			dfsColoring(v, 0, adjList, color, parent, cycles);
		}
	}


	int validIndex = -1;
	for (int idx = 0; idx < cycles.size(); idx++) {
		int nodes = cycles[idx].size();
		if (nodes >= 4) {
			validIndex = idx;
			break;
		}
	}

	if (validIndex == -1) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		vector<int> validcycle = cycles[validIndex];
		cout << validcycle.size() << endl;
		for (int& city : validcycle) {
			cout << city << " ";
		}
		cout << endl;
	}
	return 0;
}