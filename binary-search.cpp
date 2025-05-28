// https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A

#include <bits/stdc++.h>
using namespace std;
     
string binary_search(vector<int>& nums, int target) {
    int N = nums.size();
    int left = 0;
    int right = N - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return "YES";
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return "NO";
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
        cout << binary_search(nums, element) << endl;
    }
  return 0;
}