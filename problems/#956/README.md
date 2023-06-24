# Problem 956 - Tallest Billboard

## V1

Time Complexity: O(s)

Space Complexity: O(s)

- State: the height of the short steel when having diff height i between two steels.
- Base cases:
    - dp[0] = 0.
- State-transition equation:
    - dp[i] = max(dp[i], dp[i - rod]).
    - dp[i] = max(dp[i], dp[i + rod] + rod).
