#include <bits/stdc++.h>
using namespace std;


list<int> performOperation(vector<int>& originalArray, int& N) {
	list<int> answer;
	int left = 0;
	int right = N - 1;

	while (left <= right) {
		if (left == right) {
			int randomNum = rand();
			if (randomNum % 2 == 0) answer.push_front(originalArray[left]);
			else answer.push_back(originalArray[right]);
			break;
		}
		if (originalArray[left] < originalArray[right]) {
			answer.push_front(originalArray[left]);
			left += 1;
		} else {
			answer.push_back(originalArray[right]);
			right -= 1;
		}
	}

	return answer;
}

bool checkIsAnswerEqual(vector<int>& nums, list<int>& answer, int& N) {
	list<int>::iterator it;
	int idx;
	for (idx = 0, it = answer.begin(); it != answer.end(); it++, idx++) {
		if (nums[idx] != *it) return false;
	}

	return true;
}

void printArray(vector<int>& arr, int& N) {
	for (int idx = 0; idx < N; idx++) {
		cout << arr[idx] << " ";
	}

	cout << endl;
}

void printList(list<int>& answer) {
	list<int>::iterator it;

	for (it = answer.begin(); it != answer.end(); ++it) {
		cout << *it << " ";
	}

	cout << endl;
	cout << "============\n";
}

vector<int> calculateOriginalPermutation(vector<int>& nums, int& N) {
	vector<int> answer;
	int start = 0;
	int end = N - 1;
	if (nums[start] == N) {
		answer.push_back(N);
		start += 1;
	}
	else {
		end -= 1;
	}

	for (int idx = end; idx >= start; idx--) {
		answer.push_back(nums[idx]);
	}

	if (nums[N - 1] == N) answer.push_back(N);

	return answer;
}

bool isPermutationPossible(vector<int>& nums, int& N) {
	if (nums[0] == N || nums[N - 1] == N) return true;
	return false;
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
		vector<int> nums(N);

		for (int idx = 0; idx < N; idx++) {
			cin >> nums[idx];
		}

		if (!isPermutationPossible(nums, N)) {
			cout << -1 << endl;
		} else {
			nums = calculateOriginalPermutation(nums, N);
			printArray(nums, N);
		}

	}
	return 0;
}