#include <bits/stdc++.h>
using namespace std;

int answer = 0;
unordered_map<string, int> hashMap;

bool isValidPermutation(string str, int& L) {
	int N = str.length();
	if (str.length() < L) return false;
	for (int idx = 1; idx < N; idx++) {
		if (str[idx] == str[idx - 1]) return false;
	}

	return true;
}
void permute(string a, int l, int r, int& N)
{
	if (l == r) {
		if (isValidPermutation(a, N)) {
			if (hashMap[a]) answer -= 1;
			hashMap[a] = 1;
			answer += 1;
		}
	}
	else
	{
		for (int i = l; i <= r; i++)
		{

			swap(a[l], a[i]);
			permute(a, l + 1, r, N);
			swap(a[l], a[i]);
		}
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
	int N = str.length();
	permute(str, 0, str.length() - 1, N);

	cout << answer << endl;
	return 0;
}