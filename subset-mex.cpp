// https://codeforces.com/contest/1406/problem/A
#include <bits/stdc++.h>
using namespace std;

int findMex(vector<int> subset) {
	unordered_map<int, int> freqMap;
	for (int elt : subset) freqMap[elt] += 1;
	int current = 0;
	while (freqMap[current] > 0) {
		current += 1;
	}

	return current;
}


int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int T;
	cin >> T;
	while (T-- > 0) {
		int N;
		cin >> N;
		vector<int> elements(N);
		unordered_map<int, int> freqMap;

		for (int idx = 0; idx < N; idx++) {
			cin >> elements[idx];
			freqMap[elements[idx]] += 1;
		}

		int minRepeating = -1;
		for (int idx = 0; idx < N; idx++) {
			int elt = elements[idx];
			int freq = freqMap[elt];
			if (freq > 1) {
				if (minRepeating == -1) minRepeating = elt;
				else minRepeating = min(minRepeating, elt);
			}
		}

		if (minRepeating == -1) cout << findMex(elements) << endl;
		else {
			vector<int> A;
			vector<int> B;
			bool fillInA = true;
			sort(elements.begin(), elements.end());

			for (int idx = 0; idx < N; idx++) {
				int elt = elements[idx];
				if (elt == minRepeating) {
					if (fillInA) A.push_back(elt);
					else B.push_back(elt);
					fillInA = !fillInA;
				} else {
					if (!A.size()) {
						A.push_back(elt);
						continue;
					}
					int lastElt = A[A.size() - 1];
					if (lastElt + 1 == elt) A.push_back(elt);
					else B.push_back(elt);
				}
			}

			cout << findMex(A) + findMex(B) << endl;
		}

	}
	return 0;
}