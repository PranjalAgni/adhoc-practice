#include <bits/stdc++.h>
using namespace std;

void print(vector<int>& nums) {
	for (int& num : nums) {
		cout << num << " ";
	}

	cout << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif

	int N, K;
	cin >> N >> K;
	vector<int> nums(N);
	for (int idx = 0; idx < N; idx++) {
		cin >> nums[idx];
	}

	vector<int> numsCopy(nums.begin(), nums.end());
	nth_element(numsCopy.begin(), numsCopy.begin() + K - 1, numsCopy.end(), greater<int>());
	int frequency = count(numsCopy.begin(), numsCopy.begin() + K, numsCopy[K - 1]);
	cout << numsCopy[K - 1] << " " << frequency << endl;
	vector<int> answer;
	for (int& elt : nums) {
		if (elt > numsCopy[K - 1] || (elt == numsCopy[K - 1] && frequency-- > 0)) {
			answer.push_back(elt);
		}
	}
	print(answer);
	return 0;
}