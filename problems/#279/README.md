# Problem 279 - Perfect Squares

## V1

Time Complexity: O(n^2)

Space Complexity: O(n)

- State: the least number of perfect square numbers which powered by the number lower than j that sum to i.
- State-transition equation:
    - dp[i][j] = min(dp[i - pow(k, 2)][k] for k in range(j, 0, -1)).
