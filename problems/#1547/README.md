# Problem 1547 - Minimum Cost to Cut a Stick

## V1

Time Complexity: O(n^3)

Space Complexity: O(n^2)

- State: the min cost for cutting the stick between i and j.
- Base cases:
    - dp[i][i + 1] = 0.
- State-transition equation:
    - dp[i][j] = max(for i < k < j, dp[i][k] + dp[k][j] + cuts[j] - cuts[i]).
