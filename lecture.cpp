#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N, M;
	cin >> N >> M;
	unordered_map<string, string> langMap;
	while (M-- > 0) {
		string a, b;
		cin >> a >> b;
		langMap[a] = (a.length() <= b.length() ? a : b);
	}

	while (N-- > 0) {
		string word;
		cin >> word;
		cout << langMap[word];
		if (N != 0) cout << " ";
	}

	return 0;
}