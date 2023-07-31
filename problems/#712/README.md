# Problem 712 - Minimum ASCII Delete Sum for Two Strings

## V1

Time Complexity: O(m * n)

Space Complexity: O(n)

- State: the ans given substrings s1[0:i] ans s2[0:j].
- Base cases:
    - dp[-1][-1] = 0.
    - dp[i][-1] = ASCII sum of chars s1[0:i].
    - dp[-1][j] = ASCII sum of chars s2[0:j].
- State-transition equation:
    - dp[i][j] = min(dp[i - 1][j - 1] if s1[i] == s2[j] else INT_MAX, dp[i][j - 1] + s2[j], dp[i - 1][j] + s1[i]).
- Compressed DP table.
