# Problem 1751 - Maximum Number of Events That Can Be Attended II

## V1

Time Complexity: O(n (k + log n))

Space Complexity: O(nk)

- State: the max value start with events[i] given quota j.
- State-transition equation:
    - dp[i][j] = max(dp[i + 1][j], dp[next available event][j - 1]).
- Binary search.
