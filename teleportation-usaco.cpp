// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

ifstream fin("teleport.in");
ofstream fout("teleport.out");

int findDistance(int x, int y) {
	return abs(x - y);
}

int main() {
	int a, b, x, y;
	fin >> a >> b >> x >> y;

	int realDistance = abs(a - b);
	int p = findDistance(a, b);
	int q = findDistance(a, x) + findDistance(b, y);
	int r = findDistance(a, y) + findDistance(b, x);

	fout << min({p, q, r}) << endl;
	return 0;
}
