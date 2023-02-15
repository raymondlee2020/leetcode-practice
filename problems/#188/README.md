# Problem 188 - Best Time to Buy and Sell Stock IV

## V1

Time Complexity: O(n * k)

Space Complexity: O(n * k)

- State: the day, the most transaction time and hold stock or not
- Base cases:
    - dp[0][j][0] = 0 (day 0 without stock).
    - dp[0][j][1] = -inf (day 0 with stock is impossible).
    - dp[i][0][0] = 0 (0 transaction time without stock).
    - dp[i][0][1] = -inf (0 transaction time with stock is impossible).
- State-transition equation:
    - dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i - 1])
    - dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i - 1])
