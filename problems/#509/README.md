# Problem 509 - Fibonacci Number

## V1

Time Complexity: O(n)

Space Complexity: O(1)

- State: the n-th num of Fibonacci Number.
- Base cases:
    - dp[0] = 0.
    - dp[1] = 1.
- State-transition equation:
    - dp[i] = dp[i - 1] + dp[i - 2].
