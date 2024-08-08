func spiralMatrixIII(rows int, cols int, rStart int, cStart int) [][]int {
	DIR, n := []int{1, 0, -1, 0, 1}, rows*cols
	ret, idx, slen := make([][]int, n), 1, 2
	ret[0] = []int{rStart, cStart}
	for i, j := rStart-1, cStart+1; idx < n; i, j = i-1, j+1 {
		for d := range 4 {
			for _ = range slen {
				i, j = i+DIR[d], j+DIR[d+1]
				if i >= 0 && i < rows && j >= 0 && j < cols {
					ret[idx] = []int{i, j}
					idx++
				}
			}
		}
		slen += 2
	}
	return ret
}