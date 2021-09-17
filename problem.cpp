#include <bits/stdc++.h>
using namespace std;

// Time: O(N) | Space: O(N)
// N = length of the word.
string getUniqueString(string word) {
	string result = "";

	unordered_map<char, bool> hashMap;

	for (char ch : word) {
		// if I see some dup char dont include it
		if (!hashMap[ch]) {
			result.push_back(ch);
		}
		hashMap[ch] = true;
	}

	return result;
}


void swap(string& word, int left, int right) {
	char temp = word[left];
	word[left] = word[right];
	word[right] = temp;
}

// Time: O(N / 2) | Space: O(1)
string reverseWord(string word) {
	int len = word.length();

	int left = 0;
	int right = len - 1;

	while (left < right) {
		swap(word, left, right);
		left += 1;
		right -= 1;
	}

	return word;
}


int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif


	string str = "abcdefab"; //irofpQZYX
	// cout << getUniqueString(str);
	cout << reverseWord(str) << endl;
	return 0;
}