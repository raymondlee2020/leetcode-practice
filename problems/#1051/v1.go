func heightChecker(heights []int) int {
	ret, expected := 0, make([]int, len(heights))
	copy(expected, heights)
	sort.Ints(expected)
	for i, height := range heights {
		if expected[i] != height {
			ret++
		}
	}
	return ret
}