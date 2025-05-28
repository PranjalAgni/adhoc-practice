// https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/A
#include <bits/stdc++.h>
using namespace std;
  
typedef long long LL;
  
bool canFitAllRectangles(LL w, LL h, LL x, LL n) {
    return (x / w) * (x / h) >= n;
}
  
LL getUpperBound(LL w, LL h, LL n) {
    long long exp = 1;
    long long x = pow(2, exp);
    while (!canFitAllRectangles(w, h, x, n)) {
        exp += 1;
        x = pow(2, exp);
    }
    
    return x;
}
  
long long getUpperBound2(LL w, LL h, LL n) {
    return max(w, h) * n;
}
  
LL binarySearch(LL w, LL h, LL n) {
    LL left = 0;
    LL right = getUpperBound(w, h, n);
    
    long long answer = right;
    while (left <= right) {
        LL mid = left + (right - left) / 2;
        if (canFitAllRectangles(w, h, mid, n)) {
            right = mid - 1;
            answer = mid; // because it will always be smaller than current answer
        } else {
            left = mid + 1;
        }
    }
    
    return answer;
}
  
int main() {
    long long w, h, n;
    cin >> w >> h >> n;
    
    cout << binarySearch(w, h, n) << endl;
    return 0;
}
