#include <bits/stdc++.h>
using namespace std;

/**

Given an array of Strings, Each string has an id and version associated with it. string with alphabetic versions are the older versions and the string with numerical versions are the new version. We need to line up the strings for renovation such that older version strings (strings with alphabetic version) need to be put first in lexicographical order. If any clashes in arrange, then arrange them as per the lexicographical order of the id. The renovated strings need to be kept as in the input order.

Example:
Input:{a a , c  b , b b, a 1, b 2}
Output:{a a , b  b , c b, a 1, b 2}

**/


bool comparator(pair<char, char> p1, pair<char, char> p2) {
	if (p1.second == p2.second) return p1.first < p2.first;
	if (isalpha(p1.second) && isdigit(p2.second)) return true;
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N;
	cin >> N;
	vector<pair<char, char>> vp(N);

	for (int idx = 0; idx < N; idx++) {
		char a, b;
		cin >> a >> b;
		vp[idx] = {a, b};
	}

	sort(vp.begin(), vp.end(), comparator);


	for (pair<char, char> p : vp) {
		cout << p.first << " " << p.second << endl;
	}

	return 0;
}
