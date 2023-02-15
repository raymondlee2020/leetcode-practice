# Problem 122 - Best Time to Buy and Sell Stock II

## V1

Time Complexity: O(n)

Space Complexity: O(n)

- State: the day and hold stock or not
- Base cases:
    - dp[0][0] = 0 (day 0 without stock).
    - dp[0][1] = -inf (day 0 with stock is impossible).is impossible).
- State-transition equation:
    - dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i - 1])
    - dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i - 1])

