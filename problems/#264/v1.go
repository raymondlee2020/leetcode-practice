func nthUglyNumber(n int) int {
	dp, p2, p3, p5 := make([]int, n), 0, 0, 0
	dp[0] = 1
	for i := 1; i < n; i++ {
		n2, n3, n5 := dp[p2]*2, dp[p3]*3, dp[p5]*5
		dp[i] = min(n2, min(n3, n5))
		if dp[i] == n2 {
			p2++
		}
		if dp[i] == n3 {
			p3++
		}
		if dp[i] == n5 {
			p5++
		}
	}
	return dp[n-1]
}