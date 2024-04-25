# Problem 2370 - Longest Ideal Subsequence

## V1

Time Complexity: O(n)

Space Complexity: O(1)

- State: the lengh of subsequence end with i-th alphabet.
- Base cases:
    - dp[i] = 0.
- State-transition equation:
    - dp[i] = max(dp[i - k:i + k + 1]) + 1.
