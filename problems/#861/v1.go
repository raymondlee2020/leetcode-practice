func matrixScore(grid [][]int) int {
	n, m := len(grid), len(grid[0])
	ret := 1 << (m - 1) * n
	for i := 1; i < m; i++ {
		cnt := 0
		for j := range n {
			if grid[j][0] == grid[j][i] {
				cnt++
			}
		}
		ret += max(n-cnt, cnt) * (1 << (m - 1 - i))
	}
	return ret
}