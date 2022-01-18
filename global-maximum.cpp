#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& subseq) {
	for (int& elt : subseq) cout << elt << " ";
	cout << endl;
	return;
}

void generateSubsequence(vector<int>& array, int index, int& m, vector<int> subseq, vector<vector<int>>& subsequences) {
	if (index == array.size()) {
		int len = subseq.size();
		if (len == m) subsequences.push_back(subseq);
	} else {
		generateSubsequence(array, index + 1, m, subseq, subsequences);
		subseq.push_back(array[index]);
		generateSubsequence(array, index + 1, m, subseq, subsequences);
	}

}

int findMaximum(vector<int> arr, int m) {
	vector<int> subseq;
	vector<vector<int>> subsequences;
	generateSubsequence(arr, 0, m, {}, subsequences);
	int globalMaximum = 0;
	for (vector<int>& sequence : subsequences) {
		int currentMin = INT_MAX;
		for (int idx = 0; idx < m; idx++) {
			for (int jdx = idx + 1; jdx < m; jdx++) {
				int absDiff = abs(sequence[idx] - sequence[jdx]);
				if (absDiff < currentMin) {
					currentMin = absDiff;
				}
			}
		}

		if (currentMin > globalMaximum) {
			globalMaximum = currentMin;
		}
	}
	return globalMaximum;
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
	vector<int> arr(N);

	for (int idx = 0; idx < N; idx++) {
		cin >> arr[idx];
	}
	int m;
	cin >> m;

	cout << findMaximum(arr, m) << endl;;
	return 0;
}