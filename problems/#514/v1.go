func findRotateSteps(ring string, key string) int {
	n, m := len(ring), len(key)
	dp, idxes := make([][]int, n), make(map[uint8][]int)
	for idx := range n {
		idxes[ring[idx]] = append(idxes[ring[idx]], idx)
	}
	for i := range n {
		dp[i] = make([]int, m)
		for j := range m {
			dp[i][j] = -1
		}
	}
	var dfs func(i int, j int) int
	dfs = func(i int, j int) int {
		if j == m {
			return 0
		}
		if dp[i][j] != -1 {
			return dp[i][j]
		}
		ret := math.MaxInt
		for _, idx := range idxes[key[j]] {
			dist := abs(i - idx)
			ret = min(ret, dfs(idx, j+1)+min(dist, n-dist))
		}
		dp[i][j] = ret
		return ret
	}
	return dfs(0, 0) + m
}

func abs(num int) int {
	if num < 0 {
		return -num
	}
	return num
}