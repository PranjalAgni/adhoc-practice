#include <bits/stdc++.h>
using namespace std;

int computeScore(string& matchString) {
	int N = matchString.length();
	int score = 1;
	int maxScore = score;
	for (int idx = 1; idx < N; idx++) {
		if (matchString[idx] == matchString[idx - 1]) {
			score += 1;
		} else {
			maxScore = max(maxScore, score);
			score = 1;
		}
	}

	maxScore = max(maxScore, score);
	return maxScore;
}

string generateMinimumTimeline(int M, int R, int B) {
	string answer = "";
	int minScore = INT_MAX;
	for (int placement = 1; placement <= (R / 2); placement++) {
		int countR = R;
		int countB = B;
		string currentAnswer = "";
		// int currentScore = max(placement, countR - (countB * placement));
		// if (currentScore > minScore) continue;
		while (countR || countB) {
			int currentTimesR = placement;
			while (countR > 0 && currentTimesR-- > 0) {
				currentAnswer.push_back('R');
				countR -= 1;
			}

			if (countB) {
				currentAnswer.push_back('B');
				countB -= 1;
			}
		}

		// minScore = currentScore;
		// answer = currentAnswer;
		int currentScore = computeScore(currentAnswer);
		if (currentScore < minScore) {
			answer = currentAnswer;
			minScore = currentScore;
		}
	}

	return answer;
}
// R = 13 B = 6
// RRR RRR RRR RRR R
// RB RB RB RB RB RB (7)

// RRB RRB RRB RRB RRB RRB

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
		int M, R, B;
		cin >> M >> R >> B;
		string answer = generateMinimumTimeline(M, R, B);
		cout << answer << endl;
	}
	return 0;
}