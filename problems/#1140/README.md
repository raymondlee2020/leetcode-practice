# Problem 1140 - Stone Game II

## V1

Time Complexity: O(n^3)

Space Complexity: O(n^2)

- State: the max score given position i and take quota 2 * m.
- Base cases:
    - dp[i][m] = suffixSum[i] if i + m * 2 >= n.
- State-transition equation:
    - dp[i][m] = max(for 1 <= x < m * 2, suffixSums[i] - dp[i + x][max(x, m)]).
