func equalSubstring(s string, t string, maxCost int) int {
	ret, n, l, r := 0, len(s), 0, 0
	preSum := make([]int, n+1)
	for i := range n {
		preSum[i+1] = abs(int(s[i])-int(t[i])) + preSum[i]
	}
	for ; r <= n; r++ {
		if (preSum[r] - preSum[l]) > maxCost {
			ret = max(ret, r-l-1)
			for (preSum[r] - preSum[l]) > maxCost {
				l++
			}
		}
	}
	ret = max(ret, r-l-1)
	return ret
}

func abs(num int) int {
	if num < 0 {
		return -num
	}
	return num
}