#include <bits/stdc++.h>
using namespace std;

string decodeString(string& str) {
  stack<string> chars;
  stack<int> count;
  string current = "";
  int numTimes = 0;

  for (char ch : str) {
    if (isdigit(ch)) {
      numTimes = numTimes * 10 + (ch - '0');
    } else if (ch == '[') {
      count.push(numTimes);
      chars.push(current);
      current = "";
      numTimes = 0;
    } else if (ch == ']') {
      string chunk = current;
      string temp = "";
      int repeat = count.top();
      while (repeat-- > 0) temp += chunk;
      current = chars.top() + temp;
      chars.pop();
      count.pop();
    } else {
      current.push_back(ch);
    }
  }

  return current;
}

int main() {
#ifndef ONLINE_JUDGE
  // for getting input from input.txt
  freopen("input.txt", "r", stdin);
  // for writing output to output.txt
  freopen("output.txt", "w", stdout);
#endif

  string input = "3[a2[c]]";
  cout << decodeString(input) << endl;

  return 0;
}