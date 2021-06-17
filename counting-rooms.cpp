#include <bits/stdc++.h>
using namespace std;


void printGraph(vector<vector<char>>& grid) {
	for (vector<char> row : grid) {
		for (char ch : row) {
			cout << ch << " ";
		}
		cout << endl;
	}

	cout << "==============" << endl;
}


void performBFS(vector<vector<char>>& grid, int row, int col) {
	if (row < 0 || row >= grid.size() || col < 0 || col >= grid[row].size() || grid[row][col] != '.') return;

	grid[row][col] = '#';
	vector<pair<int, int>> directions = {{0, -1}, {0, 1}, { -1, 0}, {1, 0}};

	for (pair<int, int> dir : directions) {
		performBFS(grid, row + dir.first, col + dir.second);
	}

	printGraph(grid);
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int rows, cols;

	cin >> rows >> cols;
	vector<vector<char>> grid(rows, vector<char>(cols));

	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			cin >> grid[row][col];
		}
	}

	int answer = 0;
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			if (grid[row][col] == '.') {
				performBFS(grid, row, col);
				answer += 1;
			}
		}
	}

	cout << answer << endl;




	return 0;
}