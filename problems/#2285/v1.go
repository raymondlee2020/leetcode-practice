func maximumImportance(n int, roads [][]int) int64 {
	ret, degree := 0, make([]int, n)
	for _, road := range roads {
		degree[road[0]]++
		degree[road[1]]++
	}
	sort.Ints(degree)
	for i := range n {
		ret += (i + 1) * degree[i]
	}
	return int64(ret)
}