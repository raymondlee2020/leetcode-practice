# Problem 322 - Coin Change

## V1

Time Complexity: O(n)

Space Complexity: O(n)

- Top-down.
- State: the fewest number of coins needed to make up that amount.
- Base cases:
    - dp[0] = 0.
- State-transition equation:
    - dp[i] = min(for coin of coins, (dp[i - coin] + 1) if (i - coin >= 0) else INT_MAX).

## V2

Time Complexity: O(n)

Space Complexity: O(n)

- Bottom-up.
