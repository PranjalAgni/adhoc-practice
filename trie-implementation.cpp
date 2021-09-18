#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
	struct TrieNode* children[26];
	bool isLeaf;
};


struct TrieNode* getNode() {
	struct TrieNode* currentNode = new TrieNode();
	currentNode->isLeaf = false;

	for (int idx = 0; idx < 26; idx++) {
		currentNode->children[idx] = NULL;
	}

	return currentNode;
}

void insert(struct TrieNode* root, string key) {
	struct TrieNode* runnerNode = root;
	for (char ch : key) {
		int index = ch - 'a';
		if (!runnerNode->children[index]) {
			runnerNode->children[index] = getNode();
		}

		runnerNode = runnerNode->children[index];
	}

	runnerNode->isLeaf = true;
}

bool search(struct TrieNode* root, string key) {
	struct TrieNode* runnerNode = root;
	for (char ch : key) {
		int index = ch - 'a';
		if (!runnerNode->children[index]) return false;

		runnerNode = runnerNode->children[index];
	}

	return runnerNode->isLeaf;
}

int countChildren(struct TrieNode* node, int& index) {
	int count = 0;
	for (int idx = 0; idx < 26; idx++) {
		if (node->children[idx]) {
			count += 1;
			index = idx;
		}
	}

	return count;
}

string longestCommonPrefix(struct TrieNode* root) {
	string longestPrefix = "";
	struct TrieNode* runnerNode = root;
	int index;
	while (countChildren(runnerNode, index) == 1 && runnerNode->isLeaf == false) {
		runnerNode = runnerNode->children[index];
		longestPrefix.push_back('a' + index);
	}

	return longestPrefix;
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	vector<string> words = {"thisisbeautiful", "thisis", "thisisupper", "thisisbestnews", "thisisit"};
	struct TrieNode* root = getNode();
	for (string word : words) {
		insert(root, word);
	}

	cout << longestCommonPrefix(root) << endl;
	return 0;
}