# Problem 1143 - Longest Common Subsequence

## V1

Time Complexity: O(m * n)

Space Complexity: O(m * n)

- State: the length of the LCS of the first n elements in nums.
- Base cases:
    - dp[0][0] = 1 if text1[0] == text2[0] else 0.
    - dp[i][0] = 1 if text1[i] == text2[0] else dp[i - 1][0].
    - dp[0][j] = 1 if text1[0] == text2[j] else dp[0][j - 1].
- State-transition equation:
    - dp[i][j] = dp[i - 1][j - 1] + 1 if text1[i] == text2[j] elsemax(dp[i - 1][j], dp[i][j - 1]).

## V2

Time Complexity: O(m * n)

Space Complexity: O(n)

- Compressed DP table.
