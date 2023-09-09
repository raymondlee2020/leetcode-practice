# Problem 377 - Combination Sum IV

## V1

Time Complexity: O(m * n)

Space Complexity: O(m * n)

- State: the ans given target i.
- Base cases:
    - dp[i] = 0 if i > target.
    - dp[target] = 1.
- State-transition equation:
    - dp[i] = sum(dp[i + j] for j in range(0, n)).
