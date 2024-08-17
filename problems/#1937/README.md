# Problem 1937 - Maximum Number of Points with Cost

## V1

Time Complexity: O(m * n)

Space Complexity: O(n)

- State: the max point with subarray [0, i] ends at j.
- Base cases:
    - dp[i][j] = 0 if i == 0.
- State-transition equation:
    - dp[i][j] = max(dp[k] - abs(j - k) for k in range(n)) + points[i][j].
