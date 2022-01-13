#include <bits/stdc++.h>
using namespace std;


void permute(string& str, int L, int R, set<string>& answers) {
	if (L == R) {
		answers.insert(str);
	} else {
		for (int idx = L; idx <= R; idx++) {
			swap(str[L], str[idx]);
			permute(str, L + 1, R, answers);
			swap(str[L], str[idx]);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	string str;
	cin >> str;
	set<string> answers;
	int N = str.length() - 1;
	permute(str, 0, N, answers);
	cout << answers.size() << endl;

	for (auto& str : answers) {
		cout << str << endl;
	}

	return 0;
}