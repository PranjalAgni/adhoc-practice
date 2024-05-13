#include <bits/stdc++.h>
using namespace std;

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
		vector<int> arr(N);

		for (int idx = 0; idx < N; idx++) {
			cin >> arr[idx];
		}

		int start = 0;
		int end = N - 1;

		int prefixSeq = 1;
		int suffixSeq = 1;

		while (start + 1 < N && arr[start + 1] == arr[start]) {
			prefixSeq += 1;
			start += 1;
		}

		while (end - 1 >= 0 && arr[end - 1] == arr[end]) {
			suffixSeq += 1;
			end -= 1;
		}

		int exclude = 0;
		if (arr[0] == arr[N - 1]) {
			exclude = prefixSeq + suffixSeq;
		} else {
			exclude = max(prefixSeq, suffixSeq);
		}

		cout << max(0, N - exclude) << endl;

	}
	return 0;
}