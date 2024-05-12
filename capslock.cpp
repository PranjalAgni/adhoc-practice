#include <bits/stdc++.h>
using namespace std;

bool checkTyping(string& word) {
	int N = word.length();
	for (int idx = 1; idx < N; idx++) {
		if (word[idx] >= 'a' && word[idx] <= 'z') return false;
	}

	return true;

}
int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	string word;
	cin >> word;
	int N = word.length();
	bool isAccidentallyTyped = checkTyping(word);
	if (isAccidentallyTyped) {
		for (int idx = 0; idx < N; idx++) {
			word[idx] = isupper(word[idx]) ? tolower(word[idx]) : toupper(word[idx]);
		}
	}

	cout << word << endl;

	return 0;
}