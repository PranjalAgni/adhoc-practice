#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minMovesToSeat(vector<int>& seats, vector<int>& students) {
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());

    int N = seats.size();
    int answer = 0;
    for (int idx = 0; idx < N; idx++) {
      answer += abs(seats[idx] - students[idx]);
    }

    return answer;
  }
};



int main() {
#ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for writing output to output.txt
  freopen("output.txt", "w", stdout);
#endif

  Solution solution;
  cout << solution.minMovesToSeat({3, 1, 5}, {2, 7, 4}) << endl;
  return 0;
}