#include <bits/stdc++.h>
using namespace std;


/**
 * Problem Statement:
 * Given a binary tree root, return whether for every node in the tree other than the leaves, its value is equal to the sum of its left child's value and its right child's value.
**/

bool solveHelper(Tree* root) {
	if (root == NULL || (root->left == NULL && root->right == NULL)) return true;

	int sum = root->val;
	if (root->left) sum -= root->left->val;
	if (root->right) sum -= root->right->val;

	return sum == 0 && solveHelper(root->left) && solveHelper(root->right);

}

bool solve(Tree* root) {
	return solveHelper(root);
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	return 0;
}