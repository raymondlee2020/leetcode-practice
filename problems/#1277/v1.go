func countSquares(matrix [][]int) int {
    ret, n, m := 0, len(matrix), len(matrix[0])
    dp := make([][]int, n)
    for i := range n {
        dp[i] = make([]int, m)
    }
    for i := 0; i < n; i++ {
        dp[i][0] = matrix[i][0]
        ret += dp[i][0]
    }
    for j := 1; j < m; j++ {
        dp[0][j] = matrix[0][j]
        ret += dp[0][j]
    }
    for i := 1; i < n; i++ {
        for j := 1; j < m; j++ {
            if matrix[i][j] == 0 {
                continue
            }
            tmp := dp[i][j - 1]
            tmp = min(tmp, dp[i - 1][j])
            tmp = min(tmp, dp[i - 1][j - 1])
            dp[i][j] = 1 + tmp
            ret += dp[i][j]
        }
    }
    return ret
}