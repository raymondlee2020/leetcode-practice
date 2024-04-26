func minFallingPathSum(grid [][]int) int {
	var m1idx, m2idx int
	n := len(grid)
	if n == 1 {
		return grid[0][0]
	}
	for i := n - 1; i > 0; i-- {
		if grid[i][0] > grid[i][1] {
			m1idx, m2idx = 1, 0
		} else {
			m1idx, m2idx = 0, 1
		}
		for j := 2; j < n; j++ {
			if grid[i][j] < grid[i][m1idx] {
				m1idx, m2idx = j, m1idx
			} else if grid[i][j] < grid[i][m2idx] {
				m2idx = j
			}
		}
		for j := 0; j < n; j++ {
			if j == m1idx {
				grid[i-1][j] += grid[i][m2idx]
			} else {
				grid[i-1][j] += grid[i][m1idx]
			}
		}
	}
	return slices.Min(grid[0])
}