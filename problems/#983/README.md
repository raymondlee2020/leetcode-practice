# Problem 983 - Minimum Cost For Tickets

## V1

Time Complexity: O(n)

Space Complexity: O(n)

- State: the min required cost to travel to day 365 start from day i.
- Base cases:
    - dp[i] = 0 if i > 365.
- State-transition equation:
    - dp[i] = min(dp[i + 1] + costs[0], dp[i + 7] + costs[1], dp[i + 30] + costs[2]).
