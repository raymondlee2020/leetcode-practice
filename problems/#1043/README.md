# Problem 1043 - Partition Array for Maximum Sum

## V1

Time Complexity: O(n * k)

Space Complexity: O(k)

- State: the ans of subarray [i, n - 1].
- Base cases:
    - dp[i] = 0 if i > n.
- State-transition equation:
    - dp[i] = max(dp[j + 1] + MAX(subarray [i, j]) * (j - i + 1) for j in range(i, i + k)).
