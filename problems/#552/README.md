# Problem 552 - Student Attendance Record II

## V1

Time Complexity: O(n)

Space Complexity: O(1)

- State: the ans with total i absent and last j consecutive late currently.
- Base cases:
    - dp = [[1, 0, 0], [0, 0, 0]].
- State-transition equation:
    - dp = [[dp[0][0] + dp[0][1] + dp[0][2], dp[0][0], dp[0][1]], 
            [dp[0][0] + dp[0][1] + dp[0][2] + dp[1][0] + dp[1][1] + dp[1][2], dp[1][0], dp[1][1]]].
