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

	unordered_map<string, int> database;

	while (N-- > 0) {
		string str;
		cin >> str;

		if (database[str] == 0) {
			cout << "OK" << endl;
		} else {
			cout << str << database[str] << endl;
		}
		database[str] += 1;
	}
	return 0;
}


// 1 2 3 4 ...... 23

// 1 23
// 2 22
// 3 21
// 4 20
// 5 19
// 6 18
// 7 17
// 8 16
// 9 15
// 10 14
// 11 13
// 12 (left alone)







