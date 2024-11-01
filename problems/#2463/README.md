# Problem 2463 - Minimum Total Distance Traveled

## V1

Time Complexity: O(m * n)

Space Complexity: O(m * n)

- State: ans given robot[i:] and factory[j:].
- Base cases:
    - dp[i][n] = INF.
- State-transition equation:
    - dp[i][j] = min(
        sum(abs(robot[x] - factory[j][0]) for x in range(i, m))
        + dp[k][j + 1]
        - sum(abs(robot[y] - factory[j][0]) for y in range(k, m))
        for k in range(i, i + factory[j][1])
    ).
