#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif

    return 0;
}


Write a calculator function that takes a mathematical string expression and return the results.


        i / p = (2 - 3 * 5) + 1


                operand = [1, 5, 3, 2]
                          operator = [+, *, -]

                          [5, *, 3, -, 2]

                          [2, -, 3, *, 5]

                          i / p = 4 + (2 * 3 - (1 / 2  - 4) + 4)

                                  [4, +, (2 * 3, -, (1, /, 2, -, 4), + , 4]

                                   [4, +, (2 * 3, -, ]

                                    1 / 2 - 8