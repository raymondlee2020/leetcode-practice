# Problem 312 - Burst Balloons

## V1

Time Complexity: O(n^3)

Space Complexity: O(n^2)

- State: the ans given nums [i:j].
- State-transition equation:
    - dp[i][j] = max(nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j] for k in range(i, j)).
