# Problem 139 - Word Break

## V1

Time Complexity: O(n^2)

Space Complexity: O(n)

- State: substring s[0:i - 1] can be breaked into words.
- Base cases:
    - dp[0] = true.
- State-transition equation:
    - dp[i] |= dp[j] && (s[j:i - 1] is in words).
