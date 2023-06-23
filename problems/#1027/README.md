# Problem 1027 - Longest Arithmetic Subsequence

## V1

Time Complexity: O(n^2)

Space Complexity: O(n^2)

- State: the lengh of subsequence end with nums[i] with diff j.
- Base cases:
    - dp[i][j] = 2 if dp[i'][j] does not exist.
- State-transition equation:
    - dp[i][j] = dp[i'][j] + 1.
