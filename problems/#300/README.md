# Problem 300 - Longest Increasing Subsequence

## V1

Time Complexity: O(n^2)

Space Complexity: O(n)

- State: the length of the LIS of the first n elements in nums.
- Base cases:
    - dp[i] = 1 (LIS at least has the n-th element).
- State-transition equation:
    - dp[i] = max(for 0 <= j < i, dp[j] if (nums[j] < nums[i]) else -1).

## V2

Time Complexity: O(n log n)

Space Complexity: O(n)

- Binary search.
