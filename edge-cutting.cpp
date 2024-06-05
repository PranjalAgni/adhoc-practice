#include <bits/stdc++.h>
using namespace std;

void dbg(int node, vector<int> currentState) {
	cout << "Node " << node << endl;
	cout << currentState[0] << " " << currentState[1] << " " << currentState[2] << endl;
}
vector<int> dfs(unordered_map<int, vector<int>>& adjList, vector<int>& target, vector<char>& colors, int node, int parent, int& answer) {
	vector<int> currentState = {colors[node] == 'R', colors[node] == 'G', colors[node] == 'B'};


	for (int& neighbour : adjList[node]) {
		if (neighbour == parent) continue;
		vector<int> color_state = dfs(adjList, target, colors, neighbour, node, answer);
		if ((color_state[0] == target[0] && color_state[1] == 0) || (color_state[0] == 0 && color_state[1] == target[1])) {
			dbg(neighbour, color_state);
			answer += 1;
		}

		currentState[0] += color_state[0];
		currentState[1] += color_state[1];
		currentState[2] += color_state[2];
	}

	return currentState;

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

	vector<char> colors(nodes + 1);
	int redNodes = 0, greenNodes = 0, blueNodes = 0;
	for (int node = 1; node <= nodes; node++) {
		cin >> colors[node];
		if (colors[node] == 'R') redNodes += 1;
		else if (colors[node] == 'G') greenNodes += 1;
		else {
			blueNodes += 1;
		}
	}

	cout << "Total rn = " << redNodes << endl;
	cout << "Total gn = " << greenNodes << endl;

	int T = edges;
	unordered_map<int, vector<int>> adjList;

	while (T-- > 0) {
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}

	int answer = 0;
	vector<int> target = {redNodes, greenNodes, blueNodes};
	dfs(adjList, target, colors, 1, -1, answer);
	cout << "Answer = " << answer << endl;

	return 0;
}