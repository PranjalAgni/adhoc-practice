#include <bits/stdc++.h>
using namespace std;

void topologicalSortDFS(int src, unordered_map<int, vector<int>>& adjList, vector<int>& visited, stack<int>& orderStack) {
	if (visited[src] == 1) {
		return;
	}

	visited[src] = 1;
	for (int& child : adjList[src]) {
		if (visited[child] == 0) {
			topologicalSortDFS(child, adjList, visited, orderStack);
		}
	}

	orderStack.push(src);
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

	stack<int> orderStack;
	vector<int> visited(n + 1, 0);

	for (int v = 0; v <= n; v++) {
		if (visited[v] == 0) {
			topologicalSortDFS(v, adjList, visited, orderStack);
		}
	}

	while (!orderStack.empty()) {
		cout << orderStack.top() << " ";
		orderStack.pop();
	}
	cout << endl;
	return 0;
}