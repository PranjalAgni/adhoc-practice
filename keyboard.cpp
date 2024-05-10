#include <bits/stdc++.h>
using namespace std;

void addRowToKeyboard(unordered_map<char, pair<char, char>>& keymap, string row) {
	int N = row.length();
	for (int idx = 0; idx < N; idx++) {
		char l = '$';
		char r = '$';
		if (idx - 1 >= 0) {
			l = row[idx - 1];
		}

		if (idx + 1 < N) {
			r = row[idx + 1];
		}

		keymap[row[idx]] = make_pair(l, r);
	}
}
int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	unordered_map<char, pair<char, char>> keymap;
	addRowToKeyboard(keymap, "qwertyuiop");
	addRowToKeyboard(keymap, "asdfghjkl;");
	addRowToKeyboard(keymap, "zxcvbnm,./");

	char direction;
	cin >> direction;

	string word;
	cin >> word;

	int N = word.length();
	string answer = "";
	for (int idx = 0; idx < N; idx++) {
		char ch = word[idx];
		pair<char, char> neighbour = keymap[ch];
		if (direction == 'L') {
			answer += neighbour.second;
		} else {
			answer += neighbour.first;
		}
	}

	cout << answer << endl;
	return 0;
}