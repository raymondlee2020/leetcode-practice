# Problem 808 - Soup Servings

## V1

Time Complexity: O(n^2)

Space Complexity: O(n^2)

- State: the answer given A type soup i and B type soup j.
- Base cases:
    - dp[i][j] = 1 if i > 4800 and j > 4800.
- State-transition equation:
    - dp[i][j] = 0.25 * (dp[i - 4][j] + dp[i - 3][b - 1] + dp[i - 2][j - 2] + dp[i - 1][j - 3]).
