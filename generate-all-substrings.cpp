#include <bits/stdc++.h>
using namespace std;


void permuteString(string str) {
	for (int idx = 0; idx < str.length(); idx++) {
		swap(str[0], str[idx]);
		cout << str << endl;
		swap(str[0], str[idx]);
	}
}


int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	string str;
	cin >> str;

	permuteString(str);

	return 0;
}