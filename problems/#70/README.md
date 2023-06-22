# Problem 70 - Climbing Stairs

## V1

Time Complexity: O(n)

Space Complexity: O(1)

- State: the amount of ways to climb to height n.
- Base cases:
    - dp[0] = 1.
    - dp[1] = 1.
- State-transition equation:
    - dp[i] = dp[i - 1] + dp[i - 2].
