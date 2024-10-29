func maxMoves(grid [][]int) int {
    ret, n, m := 0, len(grid), len(grid[0])
    dp := make([][]int, 2)
    dp[0] = make([]int, n)
    dp[1] = make([]int, n)
    for j := m - 2; j >= 0; j-- {
        for i := range n {
            dp[0][i] = 0
            if i > 0 && grid[i][j] < grid[i - 1][j + 1] {
                dp[0][i] = max(dp[0][i], dp[1][i - 1] + 1)
            }
            if grid[i][j] < grid[i][j + 1] {
                dp[0][i] = max(dp[0][i], dp[1][i] + 1)
            }
            if i < n - 1 && grid[i][j] < grid[i + 1][j + 1] {
                dp[0][i] = max(dp[0][i], dp[1][i + 1] + 1)
            }
        }
        dp[0], dp[1] = dp[1], dp[0]
    }
    for _, num := range dp[1] {
        ret = max(ret, num)
    }
    return ret
}