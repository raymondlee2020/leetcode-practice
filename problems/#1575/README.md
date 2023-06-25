# Problem 1575 - Count All Possible Routes

## V1

Time Complexity: O(n * f)

Space Complexity: O(n * f)

- State: the all possible route amount to "finish" start with city i and fuel j.
- Base cases:
    - Fuel cannot be negative.
- State-transition equation:
    - dp[i][j] = sum(dp[next][fuel - abs(locations[i] - locations[next])] if i != next else 0).
