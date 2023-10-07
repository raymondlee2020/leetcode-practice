# Problem 1420 - Build Array Where You Can Find The Maximum Exactly K Comparisons

## V1

Time Complexity: O(m * n * k)

Space Complexity: O(m * n * k)

- State: the ans given m = a, n = b and k = c.
- Base cases:
    - dp[1][b][1] = 1.
- State-transition equation:
    - dp[a][b][c] = dp[a - 1][b][c] * b + sum(dp[a - 1][i][c - 1] for i in range(1, b)).
