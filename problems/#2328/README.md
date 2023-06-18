# Problem 2328 - Number of Increasing Paths in a Grid

## V1

Time Complexity: O(m * n)

Space Complexity: O(m * n)

- State: number of increasing paths start from grid[i][j].
- State-transition equation:
    - dp[i][j] = 1 + dp[i + 1][j] + dp[i - 1][j] + dp[i][j + 1] + dp[i][j - 1].
