#include <bits/stdc++.h>
using namespace std;


int timesSubstringPresent(string& src, string target) {
	int N = src.size();
	int targetLength = target.size();
	if (targetLength == 0 || targetLength > N) return 0;
	int times = 0;
	for (int idx = 0; idx < N; idx++) {
		char ch = src[idx];
		if (ch == target[0]) {
			string segment = src.substr(idx, targetLength);
			if (segment == target) {
				times += 1;
				idx += targetLength - 2;
			}
		}

	}

	return times;
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int T;
	cin >> T;

	while (T-- > 0) {
		int N;
		cin >> N;
		string str;
		cin >> str;

		int timesMapie = timesSubstringPresent(str, "mapie");
		int timesMap = timesSubstringPresent(str, "map");
		int timesPie = timesSubstringPresent(str, "pie");


		if (!(timesMap + timesPie)) {
			cout << 0 << endl;
		} else {
			// times map present -> remove a that many times
			// times pie present -> remove i that many timesSubstringPresent
			cout << timesMap + timesPie - timesMapie << endl;
		}
		// map
		// pie

		// chars: m,a,p,i,e
	}

	// mapie
	// mmpnapie
	//
	return 0;
}