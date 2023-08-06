# Problem 920 - Number of Music Playlists

## V1

Time Complexity: O(m * n)

Space Complexity: O(m * n)

- State: the ans given the last i songs and goal j.
- Base cases:
    - dp[0][0] = 1.
    - dp[i][0] = 0 for i in range(1, m).
    - dp[0][j] = 0 for j in range(1, n).
- State-transition equation:
    - dp[i][j] = dp[i - 1][j] + dp[i][j - 1].

