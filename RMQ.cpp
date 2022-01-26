#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
// Range Minimum query

// Our goal is to answer all Q queries in O(1) time
// i.e. precompute and store the min for all possible queries
// and just answer them directly in constant time

/** Sparse tables
 *
 * I/P: 7 2 3 0 5 10 3 12 18
 * N = 9
 *
 * Precompute min of all subarrays of size 2^j
 * i.e. multiple of 2 (1,2,4,8....)
 *
 *
 * How we will store these min values of size 2^j
 *
 * We will use a table (matrix) with rows as N and cols as closest power of 2
 * matrix[i][j] 0 to 2^j-1
 * [0][0] 0 to 0
 * [0][1] 0 to 1
 * [0][2] 0 to 3
 * [0][3] 0 to 7
**/

int getClosestPowerOf2(int N) {
	int powerOf2 = 0;
	int val = 1;
	while (val <= N) {
		val *= 2;
		powerOf2 += 1;
	}

	return powerOf2;
}

void printSparseTable(vector<vector<int>>& sparseTable) {
	for (vector<int>& row : sparseTable) {
		for (int& elt : row) {
			cout << elt << " ";
		}
		cout << endl;
	}

	return;
}

vector<vector<int>> __slowSparseTable(vector<int>& nums, int& N) {
	int K = floor(log2(N)) + 1;
	vector<vector<int>> sparseTable(N, vector<int>(K, -1));

	for (int idx = 0; idx < N; idx++) sparseTable[idx][0] = nums[idx];


	for (int idx = 0; idx < N; idx++) {
		// cout << "Starting at " << nums[idx] << " ";
		for (int exp = 1; exp <= K; exp++) {
			int size = pow(2, exp);
			int elementsWeHave = N - idx;
			if (size > elementsWeHave) continue;
			int start = 0;
			int minInWindow = nums[idx];
			while (start < size && (idx + start) < N) {
				minInWindow = min(minInWindow, nums[idx + start]);
				start += 1;
			}

			sparseTable[idx][exp] = minInWindow;
		}

	}

	printSparseTable(sparseTable);
	return sparseTable;
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N;
	cin >> N;

	vector<int> nums(N);
	for (int idx = 0; idx < N; idx++) cin >> nums[idx];

	int numQuery;
	cin >> numQuery;
	vector<pair<int, int>> queries(numQuery);

	for (int idx = 0; idx < numQuery; idx++) {
		int L, R;
		cin >> L >> R;
		queries[idx] = make_pair(L, R);
	}
	vector<int> LOG(MAXN);
	LOG[1] = 0;
	for (int i = 2; i <= MAXN; i++) {
		LOG[i] = LOG[i / 2] + 1;
	}

	vector<vector<int>> st = __slowSparseTable(nums, N);

	for (pair<int, int>& query : queries) {
		int L = query.first;
		int R = query.second;
		int j = getClosestPowerOf2(R - L + 1) - 1;
		// int j = LOG[R - L + 1];
		// cout << (R - L + 1) << " " << j << " " << jj << endl;
		int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
		cout << minimum << endl;

	}


	return 0;
}