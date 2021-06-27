#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& tasks, int k) {

    int totalTime = 0;
    int N = tasks.size();
    unordered_map<int, int> taskMap;

    int idx = 0;
    int clockTime = 1;
    for (int task : tasks) {
        if (taskMap.find(task) != taskMap.end()) {
            int lastTime = taskMap[task] + 1;
            int timeLeft = clockTime - lastTime;
            if (timeLeft <= k) {
                totalTime += (k - timeLeft);
                clockTime += k - timeLeft;
            }
        }

        taskMap[task] = clockTime;
        clockTime += 1;
        totalTime += 1;
        idx += 1;
    }

    return totalTime;
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
    vector<int> tasks(N);

    for (int idx = 0; idx < N; idx++) {
        cin >> tasks[idx];
    }

    cout << solve(tasks, K) << endl;
    return 0;
}