# Problem 688 - Knight Probability in Chessboard

## V1

Time Complexity: O(8^k)

Space Complexity: O(8^k)

- State: the possibility of knight on the board given chess on [r, c] and still have k moves.
- State-transition equation:
    - dp[i] = dp[r - 1][c - 2][k - 1] + dp[r - 2][c - 1][k - 1] +
              dp[r - 1][c + 2][k - 1] + dp[r - 2][c + 1][k - 1] +
              dp[r + 1][c - 2][k - 1] + dp[r + 2][c - 1][k - 1] +
              dp[r + 1][c + 2][k - 1] + dp[r + 2][c + 1][k - 1].
