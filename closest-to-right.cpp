// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C

#include <bits/stdc++.h>
using namespace std;
  
int binary_search_right(vector<int>& nums, int element) {
    int N = nums.size();
    int left = 0;
    int right = N - 1;
    
    int answer = N + 1;  
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= element) {
            answer = min(answer, mid + 1);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return answer;
}
int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    
    for (int idx = 0; idx < n; idx++) {
        cin >> nums[idx];
    }
    
    while(k-- > 0) {
        int element;
        cin >> element;
        cout << binary_search_right(nums, element) << endl;
    }
  return 0;
}