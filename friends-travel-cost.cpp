#include <bits/stdc++.h>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	long long N, K;
	cin >> N >> K;

	vector<pair<long long, long long>> vp;

	for (int idx = 0; idx < N; idx++) {
		long long villageIdx, numKens;
		cin >> villageIdx >> numKens;
		vp.push_back({villageIdx, numKens});
	}

	sort(vp.begin(), vp.end());

	int len = vp.size();

	long long currStation = 0;

	for (int idx = 0; idx < len; idx++) {
		long long friendStation = vp[idx].first;
		long long numKensReqd = friendStation - currStation;
		if (K < numKensReqd) {
			break;
		}

		K = K - numKensReqd + vp[idx].second;
		currStation = friendStation;
	}

	cout << currStation + K << endl;
	return 0;
}