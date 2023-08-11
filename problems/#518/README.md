# Problem 518 - Coin Change II

## V1

Time Complexity: O(m*n)

Space Complexity: O(m*n)

- State: the ans given i types of coin and amount j.
- Base cases:
    - dp[0][0] = 0.
    - dp[i][0] = 1.
- State-transition equation:
    - dp[i][j] = dp[j - 1][j] + dp[i][j - coins[i - 1]] if (j - coins[i - 1] >= 0) else dp[i - 1][j].
