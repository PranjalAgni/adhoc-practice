#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> hashMap;

// assumes 0 based indexing
char getElementByPos(vector<char> alpha, int eltPos) {
	int currPos = 0;
	for (int idx = 0; idx < alpha.size(); idx++) {
		if (hashMap[idx]) continue;
		if (currPos == eltPos) {
			hashMap[idx] = 1;
			return alpha[idx];
		}

		currPos += 1;
	}

	return 'z';
}



vector<int> calculateFactorial(int N) {
	vector<int> fact(N);
	fact[0] = 1;
	for (int idx = 1; idx < N; idx++) {
		fact[idx] = fact[idx - 1] * (idx);
	}

	return  fact;
}


// Time: O(N) | Space: O(N)
int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	string S;
	int K;

	cin >> S >> K;
	int len = S.length();


	vector<char> alpha(len);

	for (int idx = 0; idx < len; idx++) {
		alpha[idx] = S[idx];
	}


	vector<int> fact = calculateFactorial(len);

	// we are dealing with 0 based indexing so it will be (K-1)th permutation
	K -= 1;

	int N = len;
	string answer = "";

	while (N > 0) {
		int group = N;
		int groupSize = fact[group - 1];
		int eltPos = K / groupSize;
		char elt = getElementByPos(alpha, eltPos);
		answer += elt;
		K = K % groupSize;
		N -= 1;
	}

	cout << answer << endl;
	return 0;
}