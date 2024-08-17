func maxPoints(points [][]int) int64 {
	m, n := len(points), len(points[0])
	ret, dp := int64(math.MinInt64), make([]int64, n)
	for i, cell := range points[0] {
		dp[i] = int64(cell)
	}
	for i := 1; i < m; i++ {
		tmp, lmax, rmax := make([]int64, n), make([]int64, n), make([]int64, n)
		lmax[0] = dp[0]
		for j := 1; j < n; j++ {
			lmax[j] = max(lmax[j-1], dp[j]+int64(j))
		}
		rmax[n-1] = dp[n-1] - int64(n-1)
		for j := n - 2; j >= 0; j-- {
			rmax[j] = max(rmax[j+1], dp[j]-int64(j))
		}
		for j := range n {
			tmp[j] = max(lmax[j]-int64(j), rmax[j]+int64(j)) + int64(points[i][j])
		}
		dp = tmp
	}
	for _, cand := range dp {
		if cand > ret {
			ret = cand
		}
	}
	return ret
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}

func abs(num int) int {
	if num < 0 {
		return -num
	}
	return num
}