#include <bits/stdc++.h>
using namespace std;

int getClockWisePosition(int N, int K, int current) {
	int nextPlayer = current + K;
	if (nextPlayer > N) return nextPlayer % N;
	return nextPlayer;
}

string makeKey(int X, int K, char direction) {
	return to_string(X) + "-" + to_string(K) + "-" + direction;
}

void recurse(int& N, vector<pair<int, char>>& information, vector<set<int>>& states, int index, unordered_map<string, set<int>>& dp) {
	if (index >= information.size()) return;
	int lastPos = states.size() - 1;
	pair<int, char>& info = information[index];
	int distance = info.first % N;
	char dir = info.second;
	if (distance > 0) {
		set<int> lastState = states[lastPos];
		set<int> nextState;
		for (auto& x : lastState) {
			set<int> possibleStates;
			string key = makeKey(x, distance, dir);
			if (dp.find(key) != dp.end()) {
				// its present
				possibleStates = dp[key];
				// newFoundState.insert(memoized.begin(), memoized.end());
			} else {
				// we need to compute
				if (dir == '0' || dir == '1') {
					if (dir == '1') {
						// converting distance from  to clockwise
						int clockwisedir = N - distance;
						int nextPlayer = getClockWisePosition(N, clockwisedir, x);
						possibleStates.insert(nextPlayer);
						// if (clockwisedir > N) clockwisedir %= players;
					} else {
						int nextPlayer = getClockWisePosition(N, distance, x);
						possibleStates.insert(nextPlayer);
					}
				} else {
					// can be both (?)
					// find clockwise & anti-clock distances for x
					int nextPlayerAntiClockA = getClockWisePosition(N, N - distance, x);
					int nextPlayerClockA = getClockWisePosition(N, distance, x);
					possibleStates.insert({nextPlayerAntiClockA, nextPlayerClockA});
				}

				dp[key] = possibleStates;
			}

			nextState.insert(possibleStates.begin(), possibleStates.end());
		}

		if (nextState.size() > 0) {
			states.push_back(nextState);
			// recurse(N, information, states, index + 1, dp);
		}

	}

	recurse(N, information, states, index + 1, dp);
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
		int n, m, x;
		cin >> n >> m >> x;
		vector<pair<int, char>> information;
		int distance;
		char direction; // ('0', '1', '?')
		for (int idx = 0; idx < m; idx++) {
			cin >> distance >> direction;
			information.push_back(make_pair(distance, direction));
		}

		vector<set<int>> states;
		states.push_back({x});
		unordered_map<string, set<int>> dp;
		recurse(n, information, states, 0, dp);

		set<int> possiblePos = states[states.size() - 1];
		cout << possiblePos.size() << endl;
		for (auto& p : possiblePos) {
			cout << p << " ";
		}

		if (T != 0) cout << endl;
	}


	return 0;
}