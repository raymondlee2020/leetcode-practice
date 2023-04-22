# Problem 879 - Profitable Schemes

## V1

Time Complexity: O(m*n*k)

Space Complexity: O(m*n*k)

- State: the profitable scheme given min profit i, max people j, and crime subarray [k, len(crime)).
- Base cases:
    - dp[i][-1][k] = 0.
    - dp[i][j][len(crime)] = 0 if i > 0 else 1.
- State-transition equation:
    - dp[i][j][k] = dp[i][j][k + 1] + dp[i - crimeProfit[k]][j - crimeGroup[k]][k + 1].
    - Any case that i - crimeProfit[k] > 0 should update the index to 0.