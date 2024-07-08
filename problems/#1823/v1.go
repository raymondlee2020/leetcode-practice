func findTheWinner(n int, k int) int {
	ret := 0
	for i := range n {
		ret = (ret + k) % (i + 1)
	}
	return ret + 1
}