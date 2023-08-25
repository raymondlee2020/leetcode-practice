# Problem 97 - Interleaving String

## V1

Time Complexity: O(m*n)

Space Complexity: O(m*n)

- State: the ans given s1 = s1[:i] and s2 = s2[:j].
- Base cases:
    - dp[0][0] = true.
- State-transition equation:
    - dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1].
    - dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1].
    - dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]) if (i > 0 && j > 0).
