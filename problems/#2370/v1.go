func longestIdealString(s string, k int) int {
	ret, dp := 1, make([]int, 26, 26)
	for _, c := range s {
		i := int(c - 'a')
		dp[i] = slices.Max(dp[max(i-k, 0):min(i+k+1, 26)]) + 1
		ret = max(ret, dp[i])
	}
	return ret
}