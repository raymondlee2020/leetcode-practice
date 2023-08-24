# Problem 741 - Cherry Pickup

## V1

Time Complexity: O(n^4)

Space Complexity: O(n^4)

- As two people start from grid[0][0]
- State: the ans given one person start from grid[i][j] and another from frid[k][l].
- Base cases:
    - dp[i][j][k][l] = -1 if grid[i][j] == -1 || grid[k][l] == -1.
- State-transition equation:
    - dp[i][j][k][l] = (grid[i][j] if (i == k && j == l) else grid[i][j] + grid[k][l]).
