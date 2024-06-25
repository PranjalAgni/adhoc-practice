#include <bits/stdc++.h>
using namespace std;


void dfsColoring(int src, int par, unordered_map<int, vector<int>>& adjList, vector<int>& color, vector<int>& parent, vector<vector<int>>& cycles) {
	int N = cycles.size();
	if (color[src] == 2 || N > 0) {
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
		while (curr != src && curr != 0) {
			curr = parent[curr];
			cycle.push_back(curr);
		}

		// starting from a city and visiting 1 or more city
		// so at minimum visit 2 cities
		if (cycle.size() >= 2) {
			reverse(cycle.begin(), cycle.end());
			cycle.push_back(curr);
			cycles.push_back(cycle);
		}
		return;
	}

	parent[src] = par;
	color[src] = 1;

	for (int& neighbour : adjList[src]) {
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
	}


	vector<int> color(n + 1, 0);
	vector<int> parent(n + 1);
	vector<vector<int>> cycles;

	for (int v = 1; v <= n; v++) {
		if (color[v] != 2) {
			dfsColoring(v, 0, adjList, color, parent, cycles);
		}
	}

	// printing all the cycles
	int cyclesFormed = cycles.size();
	if (cyclesFormed == 0) {
		cout << "IMPOSSIBLE" << endl;
	} else {
		cout << cycles[0].size() << endl;
		for (int& n : cycles[0]) {
			cout << n << " ";
		}
		cout << endl;
	}
	return 0;
}