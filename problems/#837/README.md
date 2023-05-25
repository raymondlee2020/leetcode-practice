# Problem 837 - New 21 Game

## V1

Time Complexity: O(n)

Space Complexity: O(n)

- State: the prob of getting i points
- Base cases:
    - dp[0] = 1.
- State-transition equation:
    - dp[i] = WINDOW_PROB_SUM * (1 / MAXPTS).
