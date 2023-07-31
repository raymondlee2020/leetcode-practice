# Problem 664 - Strange Printer

## V1

Time Complexity: O(n^3)

Space Complexity: O(n^2)

- State: the answer given substring s[i: j].
- Base cases:
    - dp[i][i] = 1.
- State-transition equation:
    - dp[i][j] = min(dp[i][k] + dp[k][j] for k in range(i, j)).
