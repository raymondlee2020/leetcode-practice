# Problem 72 - Edit Distance

## V1

Time Complexity: O(m * n)

Space Complexity: O(n)

- State: the ans given substrings word1[0:i] nd word2[0:j].
- Base cases:
    - dp[i][0] = i + 1.
    - dp[0][j] = j + 1.
- State-transition equation:
    - dp[i][j] = dp[i - 1][j - 1] if word1[i] == word2[j] else min(dp[i - 1][j - 1], dp[i][j - 1], dp[i - 1][j]) + 1.
    - Three ways to tansit:
        - Replace (dp[i - 1][j - 1] + 1).
        - Insert (dp[i][j - 1] + 1).
        - Delete (dp[i - 1][j]).
