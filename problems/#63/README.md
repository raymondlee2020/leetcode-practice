# Problem 63 - Unique Paths II

## V1

Time Complexity: O(m*n)

Space Complexity: O(n)

- State: the ans given the destination obstacleGrid[i][j]
- Base cases:
    - dp[0][0] = 1.
- State-transition equation:
    - dp[i][j] =  dp[i - 1][j] + dp[i][j - 1] if obstacleGrid[i][j] == 0 else 0.
