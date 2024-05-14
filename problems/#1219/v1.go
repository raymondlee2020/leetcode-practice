var m, n int
var DIR = []int{0, 1, 0, -1, 0}

func getMaximumGold(grid [][]int) int {
	m, n = len(grid), len(grid[0])
	ret := checkIfAllNonEmpty(grid)
	if ret != 0 {
		return ret
	}
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			ret = max(ret, backtrack(grid, i, j))
		}
	}
	return ret
}

func checkIfAllNonEmpty(grid [][]int) int {
	ret := 0
	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			if grid[i][j] == 0 {
				return 0
			}
			ret += grid[i][j]
		}
	}
	return ret
}

func backtrack(grid [][]int, i int, j int) int {
	if i < 0 || i == m || j < 0 || j == n || grid[i][j] == 0 {
		return 0
	}
	ret, tmp := 0, grid[i][j]
	grid[i][j] = 0
	for k := range 4 {
		ret = max(ret, backtrack(grid, i+DIR[k], j+DIR[k+1]))
	}
	ret += tmp
	grid[i][j] = tmp
	return ret
}