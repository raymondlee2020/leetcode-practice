func findRelativeRanks(score []int) []string {
	ret, n, m := make([]string, len(score)), len(score), make(map[int]int)
	rank := map[int]string{
		0: "Gold Medal",
		1: "Silver Medal",
		2: "Bronze Medal",
	}
	for i, score := range score {
		m[score] = i
	}
	sort.Sort(sort.Reverse(sort.IntSlice(score)))
	for i := range min(n, 3) {
		ret[m[score[i]]] = rank[i]
	}
	for i := 3; i < n; i++ {
		ret[m[score[i]]] = strconv.Itoa(i + 1)
	}
	return ret
}