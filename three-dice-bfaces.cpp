#include <bits/stdc++.h>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int a, b, c;
	cin >> a >> b >> c;

	int sumBottomFace = (7 - a) + (7 - b) + (7 - c);
	cout << sumBottomFace << endl;
	return 0;
}