// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int n, int x, int y, int currentTime) {
    int a = currentTime / x;
    int b = currentTime / y;
    
    return (a + b) >= n;
}
  
int binarySearch(int n, int x, int y) {
    int left = 1;
    int right = n * min(x, y);
    int answer = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isPossible(n, x, y, mid)) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return answer;
}
  
int main() {
    int n, x, y;
    cin >> n >> x >> y;
    
    if (n == 1) {
        cout << min(x, y) << endl;
        return 0;
    }
    
    // make one more copy so we can do 2 simultaneously
    int time = min(x ,y);
    cout << time + binarySearch(n - 1, x, y) << endl;
    return 0;
}