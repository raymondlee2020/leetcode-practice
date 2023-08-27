# Problem 403 - Frog Jump

## V1

Time Complexity: O(n^2)

Space Complexity: O(n^2)

- State: the ans given position i and last jump units j.
- Base cases:
    - dp[i][j] = false if i > n.
- State-transition equation:
    - dp[i][j] = dp[i + j - 1][j - 1] || dp[i + j][j] || dp[i + j + 1][j + 1].
