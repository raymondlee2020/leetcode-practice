func minSteps(n int) int {
    if n == 1 {
        return 0
    }
    dp := make([]int, n + 1)
    dp[1] = 0
    for i := 2; i <= n; i++ {
        dp[i] = math.MaxInt
        for f := 1; f * f <= i; f++ {
            if i % f != 0 {
                continue
            }
            dp[i] = min(dp[i], dp[f] + i / f)
            if i / f != f {
                dp[i] = min(dp[i], dp[i / f] + f)
            }
        }
    }
    return dp[n]
}