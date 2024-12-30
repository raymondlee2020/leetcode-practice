# Problem 2466 - Count Ways To Build Good Strings

## V1

Time Complexity: O(n)

Space Complexity: O(n)

- State: the count of good string for length i.
- Base cases:
    - dp[0] = 1.
- State-transition equation:
    - dp[i] = (dp[i - zero] if i - zero >= 0 else 0) + (dp[i - one] if i - one >= 0 else 0).

## V2

Time Complexity: O(n)

Space Complexity: O(n)

- Go version.