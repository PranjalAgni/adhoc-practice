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
	int day = 1;
	int sum = 1;

	while (sum < N) {
		day += 1;
		int curr = day;
		sum += curr;
	}

	cout << day << endl;

	return 0;
}