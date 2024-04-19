func islandPerimeter(grid [][]int) int {
	ret, n, m := 0, len(grid), len(grid[0])
	for i := range n {
		for j := range m {
			if grid[i][j] == 0 {
				continue
			}
			if i+1 == n || grid[i+1][j] == 0 {
				ret += 1
			}
			if i-1 < 0 || grid[i-1][j] == 0 {
				ret += 1
			}
			if j+1 == m || grid[i][j+1] == 0 {
				ret += 1
			}
			if j-1 < 0 || grid[i][j-1] == 0 {
				ret += 1
			}
		}
	}
	return ret
}