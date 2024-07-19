func luckyNumbers(matrix [][]int) []int {
	ret, m, n, cands := make([]int, 0), len(matrix), len(matrix[0]), make(map[int]bool)
	for i := range m {
		cand := math.MaxInt
		for j := range n {
			cand = min(cand, matrix[i][j])
		}
		cands[cand] = true
	}
	for j := range n {
		cand := math.MinInt
		for i := range m {
			cand = max(cand, matrix[i][j])
		}
		if cands[cand] {
			ret = append(ret, cand)
		}
	}
	return ret
}