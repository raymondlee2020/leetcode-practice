# Problem 2140 - Solving Questions With Brainpower

## V1

Time Complexity: O(n)

Space Complexity: O(n)

- State: the highest points for last i questions.
- Base cases:
    - dp[n] = 0.
- State-transition equation:
    - dp[i] = max(dp[i + 1], questions[i][0] + dp[min(n, i + questions[i][1] + 1)]).
    - dp[i + 1] means skip.
    - dp[min(n, i + questions[i][1] + 1)] means next question.
