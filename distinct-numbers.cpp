#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, elt;
	cin >> N;

	set<int> hashSet;
	for (int idx = 0; idx < N; idx++) {
		cin >> elt;
		hashSet.insert(elt);
	}

	cout << hashSet.size() << endl;
	return 0;
}