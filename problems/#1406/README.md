# Problem 1406 - Stone Game III

## V1

Time Complexity: O(n)

Space Complexity: O(n)

- State: the max score given position i.
- Base cases:
    - dp[n - 1] = suffixSum[n - 1].
- State-transition equation:
    - dp[i] = max(for 1 <= x <= 3, suffixSums[i] - dp[i + x]).
