#include <bits/stdc++.h>
using namespace std;


vector<char> getCharacterArray(string word) {
	vector<char> tokenizeWord;
	for (char ch : word) tokenizeWord.push_back(ch);
	return tokenizeWord;
}

int main() {
	int N;

	cin >> N;

	vector<string> words;

	for (int idx = 0; idx < N; idx++) {
		cin >> words[idx];
	}

	// initalized hashMap
	unordered_map<sortedWord, vector<string>> hashMap;

	for (int idx = 0; idx < N; idx++) {
		// char array "abc" = [a, b, c];
		vector<char> charList = getCharacterArray(words[idx]);
		// ['a', 'b', 'c']
		sort(charList.begin(), charList.end());
		//  "abc"
		string sortedWord = string(charList.begin(), charList.end());

		// currentAnswer = {"abc"}
		vector<string> currentAnswer = {words[idx]};
		// checking if I have seen this word before
		if (hashMap.begin(sortedWord) != hashMap.end()) {
			currentAnswer = hashMap[sortedWord];
			currentAnswer.push_back(words[idx]);

		}

		hashMap[sortedWord] = currentAnswer;
	}


	vector<vector<sting>> answer;

	for (auto currentAnswer : hashMap) {
		answer.push_back(currentAnswer.second);
	}

	for (vector<string> row : answer) {
		for (string word : row) {
			cout << word << " ";
		}

		cout << endl;
	}

	return 0;
}