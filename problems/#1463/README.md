# Problem 1463 - Cherry Pickup II

## V1

Time Complexity: O(m * n ^ 2)

Space Complexity: O(n ^ 2)

- State: max amount of cherry can be picked if robots go by column i and j at a specific row.
- State-transition equation:
    - dp[i][j] = (MAX_NUM in nine combs) + ((NUM at col i) if i == j else (NUM at col i + NUM at col j)).
