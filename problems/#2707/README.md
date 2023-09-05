# Problem 2707 - Extra Characters in a String

## V1

Time Complexity: O(n^2)

Space Complexity: O(n)

- State: the ans given substring s[i:].
- Base cases:
    - dp[n] = 0.
- State-transition equation:
    - dp[i] = min((0 if s[i:j] in dict else (j - i + 1)) + dp[j + 1] for j in range(i, n)).
