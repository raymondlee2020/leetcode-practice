# Problem 1269 - Number of Ways to Stay in the Same Place After Some Steps

## V1

Time Complexity: O(n ^ 2)

Space Complexity: O(n ^ 2)

- State: the ans given position at index i with remained steps j.
- Base cases:
    - dp[0][0] = 1.
    - dp[i][j] = 0 if i > j.
- State-transition equation:
    - dp[i][j] = dp[i][j - 1] + dp[i + 1][j - 1] + dp[i - 1][j - 1].
