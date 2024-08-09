func numMagicSquaresInside(grid [][]int) int {
	ret := 0
	for i, row := range grid {
		for j, cell := range row {
			if cell == 5 && verify(&grid, i, j) {
				ret++
			}
		}
	}
	return ret
}

func verify(grid *[][]int, i, j int) bool {
	if i == 0 || i == len(*grid)-1 || j == 0 || j == len((*grid)[0])-1 {
		return false
	}
	seq := fmt.Sprintf(
		"%d%d%d%d%d%d%d%d",
		(*grid)[i-1][j-1],
		(*grid)[i-1][j],
		(*grid)[i-1][j+1],
		(*grid)[i][j+1],
		(*grid)[i+1][j+1],
		(*grid)[i+1][j],
		(*grid)[i+1][j-1],
		(*grid)[i][j-1],
	)
	return strings.Contains("43816729438167", seq) || strings.Contains("761834927618349", seq)
}