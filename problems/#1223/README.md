# Problem 1223 - Dice Roll Simulation

## V1

Time Complexity: O(n)

Space Complexity: O(n)

- State: the ans given n = i and the last rolling is face j.
- Base cases:
    - dp[1][j] = 1 if j < 6 else 6.
- State-transition equation:
    - dp[i - 1][6] for cases without restriction.
    - dp[i - 1][6] - 1 for cases i - rollMax[j] == 1.
    - dp[i - 1][6] - (dp[i - rollMax[j] - 1][6] - dp[i - rollMax[j] - 1][j]) for cases i - rollMax[j] >= 2.
