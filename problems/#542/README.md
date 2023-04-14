# Problem 542 - 01 Matrix

## V1

Time Complexity: O(n^2)

Space Complexity: O(n^2)

- BFS.

## V2

Time Complexity: O(n)

Space Complexity: O(1)

- State: distance to the nearest 0.
- Base cases:
    - dp[-1][0] = INF.
    - dp[m][0] = INF.
    - dp[0][-1] = INF.
    - dp[0][n] = INF.
- State-transition equation:
    - dp[i][j] = min(top, bottom. left, right) + 1 =  min(min(top, left) + 1, min(bottom, right) + 1).
    - Two ways (top-left, bottom-right) DP.
