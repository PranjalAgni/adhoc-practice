// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B

// binary search on floating point
#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<float>& ropes, int k, float cutLength) {
    int count = 0;
    for (float& rope: ropes) {
        count += (rope / cutLength);
    }
    
    return count >= k;
}

float findMaxLengthOfCut(vector<float>& ropes, int k, int n) {
    float left = 0;
    float right = ropes[n - 1];
    float answer = 0;
    for (int idx = 0; idx < 100; idx++) {
        float mid = left + (right - left) / 2;
        if (isPossible(ropes, k, mid)) {
            left = mid + 1;
            answer = mid;
        } else {
            right = mid - 1;
        }
    }
    
    return answer;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<float> ropes(n);
    
    for (int idx = 0; idx < n; idx++) {
        cin >> ropes[idx];
    }
    
    sort(ropes.begin(), ropes.end());
    cout << findMaxLengthOfCut(ropes, k, n) << endl;
    return 0;
}