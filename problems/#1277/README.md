# Problem 1277 - Count Square Submatrices with All Ones

## V1

Time Complexity: O(m * n)

Space Complexity: O(m * n)

- State: the num of square with (i, j) right, bottom cell.
- Base cases:
    - dp[i][0] = matrix[i][0].
    - dp[0][j] = matrix[0][j].
- State-transition equation:
    - dp[i][j] = min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1.
