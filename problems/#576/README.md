# Problem 576 - Out of Boundary Paths

## V1

Time Complexity: O(m * n * move)

Space Complexity: O(m * n * move)

- State: the ans given start row at i, start column at j and max move with k.
- Base cases:
    - dp[i][j][0] = 0.
- State-transition equation:
    - dp[i][j][k] = dp[i + 1][j][k - 1] + dp[i - 1][j][k - 1] + dp[i][j + 1][k - 1] + dp[i][j - 1][k - 1].
