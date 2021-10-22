// https://codeforces.com/problemset/problem/977/B
#include <bits/stdc++.h>
using namespace std;


string findMostFrequestGram(unordered_map<string, int>& gramMap) {
	int highestFreq = 0;
	string answer = "";
	for (const auto [key, freq] : gramMap) {
		if (freq > highestFreq) {
			highestFreq = freq;
			answer = key;
		}
	}

	return answer;
}

string solve(string& str, int& N) {
	unordered_map<string, int> gramMap;
	for (int idx = 0; idx < N - 1; idx++) {
		string currentGram = str.substr(idx, 2);
		gramMap[currentGram] += 1;
	}


	return findMostFrequestGram(gramMap);
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

	string str;
	cin >> str;

	cout << solve(str, N) << endl;
	return 0;
}