# Problem 650 - 2 Keys Keyboard

## V1

Time Complexity: O(n log n)

Space Complexity: O(n)

- State: the ans given n = i.
- Base cases:
    - dp[1] = 0.
- State-transition equation:
    - dp[i] = min(min(dp[j] + i / j, dp[i / j] + j) for j in range(sqrt(i)) if i % f == 0)
