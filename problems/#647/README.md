# Problem 647 - Palindromic Substrings

## V1

Time Complexity: O(n ^ 3)

Space Complexity: O(1)

- None.

## V2

Time Complexity: O(n ^ 2)

Space Complexity: O(n ^ 2)

- State: substring s[i:j] is palindrome or not.
- Base cases:
    - dp[i][i] = 1.
    - dp[i][j] = 1 if i + 1 == j and s[i] == s[j] else 0.
- State-transition equation:
    - dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : 0.
