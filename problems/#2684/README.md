# Problem 2684 - Maximum Number of Moves in a Grid

## V1

Time Complexity: O(m * n)

Space Complexity: O(n)

- State: the ans given grid[:,j:].
- Base cases:
    - dp[i][m - 1] = 0.
- State-transition equation:
    - dp[i][j] = max(dp[i - 1][j + 1], dp[i][j + 1], dp[i + 1][j + 1]) + 1.
- Compressed.
