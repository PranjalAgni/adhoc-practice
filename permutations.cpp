#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N;
	cin >> N;

	if (N == 1) cout << 1 << endl;
	else if (N <= 3) cout << "NO SOLUTION" << endl;
	else {
		int start = 1;
		int end = (N % 2 == 0) ? N : N - 1;
		list<int> answer;
		while (start <= N || end > 0) {
			if (start <= N) answer.push_front(start);
			if (end > 0) answer.push_back(end);
			start += 2;
			end -= 2;
		}

		list<int>::iterator it;
		for (it = answer.begin(); it != answer.end(); it++) {
			cout << *it << " ";
		}

		cout << endl;
	}

	return 0;
}