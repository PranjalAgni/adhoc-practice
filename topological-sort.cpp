#include <bits/stdc++.h>
using namespace std;


void printGraph(vector<vector<int>>& graph) {
	int V = graph.size();
	for (int v = 0; v < V; v++) {
		cout << v << ": ";
		for (int e = 0; e < graph[v].size(); e++) {
			cout << graph[v][e] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

vector<int> getIndegreeOfVerticies(vector<vector<int>>& graph) {
	int V = graph.size();
	vector<int> indegree(V);
	for (int v = 0; v < V; v++) {
		for (int e = 0; e < graph[v].size(); e++) {
			indegree[graph[v][e]] += 1;
		}
	}

	return indegree;
}

void topologicalSort(vector<vector<int>>& graph, vector<int>& indegree, vector<int>& verticiesWithNoIncomingEdges) {
	int V = graph.size();
	vector<int> topologicalOrdering;

	while (verticiesWithNoIncomingEdges.size()) {
		int v = verticiesWithNoIncomingEdges.back();
		verticiesWithNoIncomingEdges.pop_back();
		topologicalOrdering.push_back(v);
		for (int e = 0; e < graph[v].size(); e++) {
			indegree[graph[v][e]] -= 1;
			if (indegree[graph[v][e]] == 0) {
				verticiesWithNoIncomingEdges.push_back(graph[v][e]);
			}
		}

		if (topologicalOrdering.size() == V) break;
	}


	for (int v : topologicalOrdering) {
		cout << v << " ";
	}

	return;
}

vector<int> getZeroIndegreeVerticies(vector<int>& indegree) {
	int V = indegree.size();
	vector<int> verticiesWithNoIncomingEdges;
	for (int v = 0; v < V; v++) {
		if (indegree[v] == 0) {
			verticiesWithNoIncomingEdges.push_back(v);
		}
	}

	return verticiesWithNoIncomingEdges;
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

	vector<vector<int>> graph(V);
	for (int v = 0; v < V; v++) {
		int E;
		cin >> E;
		vector<int> edges(E);
		for (int e = 0; e < E; e++) {
			int dest;
			cin >> dest;
			edges[e] = dest;
		}

		graph[v] = edges;
	}

	// printGraph(graph);

	vector<int> indegree = getIndegreeOfVerticies(graph);
	vector<int> verticiesWithNoIncomingEdges = getZeroIndegreeVerticies(indegree);
	topologicalSort(graph, indegree, verticiesWithNoIncomingEdges);
	return 0;
}