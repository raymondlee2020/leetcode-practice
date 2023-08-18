# Problem 813 - Largest Sum of Averages

## V1

Time Complexity: O(n*k)

Space Complexity: O(n*k)

- State: the ans given nums [i:] and k = j.
- Base cases:
    - dp[i][0] = 0.0 if i < n.
- State-transition equation:
    - dp[i][j] = max(mean(nums[i:k + 1]) + dp[k + 1][j - 1] for k in range(i, n)).
