#include <bits/stdc++.h>
using namespace std;

// Time: O(N) | Space: O(N)
// N = length of the word.
char firstUniqueCharacter(string word) {
	unordered_map<char, int> freqMap;

	// iterating in the word str
	for (char ch : word) {
		freqMap[ch] += 1;
	}

	for (char ch : word) {
		// this character is unique
		if (freqMap[ch] == 1) return ch;
	}

	// means end of the string.
	return '$';

}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	string word = "aabb9ef";
	cout << firstUniqueCharacter(word) << endl;
	return 0;
}