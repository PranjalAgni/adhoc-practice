#include <bits/stdc++.h>
using namespace std;

void printPatternWithoutLoop(int curr, int target, int direction) {
	cout << curr << " ";

	if (curr <= 0) {
		direction = 1;
	}

	curr = direction ? curr + 5 : curr - 5;
	if (curr == target) {
		cout << curr << " ";
		return;
	}
	printPatternWithoutLoop(curr, target, direction);
}
int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	printPatternWithoutLoop(10, 10, 0);
	return 0;
}