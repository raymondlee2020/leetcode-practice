func restoreMatrix(rowSum []int, colSum []int) [][]int {
	ret := make([][]int, len(rowSum))
	for i := range len(rowSum) {
		ret[i] = make([]int, len(colSum))
		for j := range len(colSum) {
			ret[i][j] = min(rowSum[i], colSum[j])
			rowSum[i] -= ret[i][j]
			colSum[j] -= ret[i][j]
		}
	}
	return ret
}