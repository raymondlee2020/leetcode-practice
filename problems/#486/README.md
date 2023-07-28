# Problem 486 - Predict the Winner

## V1

Time Complexity: O(n^2)

Space Complexity: O(n^2)

- State: the max score can get given interval [i, j].
- Base cases:
    - dp[i][j] = 0 if i > j.
- State-transition equation:
    - dp[i][j] = (sum of interval [0, i) and (j, n - 1]) - min(dp[i + 1][j], dp[i][j - 1]).
