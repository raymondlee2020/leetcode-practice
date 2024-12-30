func countGoodStrings(low int, high int, zero int, one int) int {
    MOD := int(1e9 + 7)
    ret, bound, dp := 0, max(high - zero, high - one) + 1, make([]int, high + max(zero, one))
    dp[0] = 1
    for i := range bound {
        dp[i + zero] = (dp[i + zero] + dp[i]) % MOD
        dp[i + one] = (dp[i + one] + dp[i]) % MOD
    }
    for i := low; i <= high; i++ {
        ret = (ret + dp[i]) % MOD
    }
    return ret
}