# Problem 1312 - Minimum Insertion Steps to Make a String Palindrome

## V1

Time Complexity: O(n^2)

Space Complexity: O(n^2)

- State: the min insertion steps to make substring [i, j + 1) palindrome.
- Base cases:
    - dp[i][j] = 0 if i == j.
- State-transition equation:
    - dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1 if s[i] == s[j] else dp[i + 1][j - 1].
- Can be solved by len(s) - (LCS of s and reverse(s)).

## V1

Time Complexity: O(n^2)

Space Complexity: O(n)

- Compressed DP table.
