# Problem 1416 - Restore The Array

## V1

Time Complexity: O(n^2)

Space Complexity: O(n)

- State: the number of the possible arrays that can be printed as substring [i, len(s)).
- Base cases:
    - The case is invalid if s[i] == '0'.
- State-transition equation:
    - dp[i] = sum(dp[j] for j in [i + 1, len(s))).
