# Problem 446 - Arithmetic Slices II - Subsequence

## V1

Time Complexity: O(n ^ 2)

Space Complexity: O(n ^ 2)

- State: the num of subsequence end with nums[i] and with diff j which length >= 2.
- State-transition equation:
    - dp[i][j] = sum((dp[k][j] + 1 if nums[i] - nums[k] == j) for k in range(i)).
