func checkRecord(n int) int {
	const MOD = 1e9 + 7
	dp := [][]int{[]int{1, 0, 0}, []int{0, 0, 0}}
	for i := 0; i < n; i++ {
		nxt := [][]int{[]int{0, 0, 0}, []int{0, 0, 0}}
		nxt[0][0] = (dp[0][0] + dp[0][1] + dp[0][2]) % MOD
		nxt[0][1] = dp[0][0]
		nxt[0][2] = dp[0][1]
		nxt[1][0] = (dp[0][0] + dp[0][1] + dp[0][2] + dp[1][0] + dp[1][1] + dp[1][2]) % MOD
		nxt[1][1] = dp[1][0]
		nxt[1][2] = dp[1][1]
		dp = nxt
	}
	ret := (dp[0][0] + dp[0][1] + dp[0][2] + dp[1][0] + dp[1][1] + dp[1][2]) % MOD
	return ret
}