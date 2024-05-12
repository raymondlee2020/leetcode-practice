func largestLocal(grid [][]int) [][]int {
	var tmp []int
	n := len(grid)
	ret := make([][]int, n-2)
	for i := range n - 2 {
		ret[i] = make([]int, n-2)
	}
	for i, row := range grid {
		tmp = make([]int, 0)
		for j, num := range row {
			if len(tmp) > 0 && j-tmp[0] > 2 {
				tmp = tmp[1:]
			}
			for len(tmp) > 0 && num > grid[i][tmp[len(tmp)-1]] {
				tmp = tmp[:len(tmp)-1]
			}
			tmp = append(tmp, j)
			if j < 2 {
				continue
			}
			grid[i][j-2] = grid[i][tmp[0]]
		}
	}
	for j := 0; j < n-2; j++ {
		tmp = make([]int, 0)
		for i := 0; i < n; i++ {
			if len(tmp) > 0 && i-tmp[0] > 2 {
				tmp = tmp[1:]
			}
			for len(tmp) > 0 && grid[i][j] > grid[tmp[len(tmp)-1]][j] {
				tmp = tmp[:len(tmp)-1]
			}
			tmp = append(tmp, i)
			if i < 2 {
				continue
			}
			ret[i-2][j] = grid[tmp[0]][j]
		}
	}
	return ret
}