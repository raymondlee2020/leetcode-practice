var n, m int

func findFarmland(land [][]int) [][]int {
	n, m = len(land), len(land[0])
	ret := [][]int{}
	for i := range n {
		for j := range m {
			if land[i][j] == 0 {
				continue
			}
			ret = append(ret, solve(land, i, j))
		}
	}
	return ret
}

func solve(land [][]int, i int, j int) []int {
	ret := []int{i, j}
	for ; i+1 < n && j+1 < m && land[i+1][j] == 1 && land[i][j+1] == 1; i, j = i+1, j+1 {
	}
	for ; i+1 < n && land[i+1][j] == 1; i++ {
	}
	for ; j+1 < m && land[i][j+1] == 1; j++ {
	}
	ret = append(ret, i, j)
	fill(land, ret)
	return ret
}

func fill(land [][]int, group []int) {
	for i := group[0]; i <= group[2]; i++ {
		for j := group[1]; j <= group[3]; j++ {
			land[i][j] = 0
		}
	}
}