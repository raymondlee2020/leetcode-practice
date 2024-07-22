func sortPeople(names []string, heights []int) []string {
	ret, tmp := make([]string, len(names)), make([][]int, len(heights))
	for i, height := range heights {
		tmp[i] = []int{height, i}
	}
	sort.Slice(tmp, func(i, j int) bool {
		return tmp[i][0] > tmp[j][0]
	})
	for i, t := range tmp {
		ret[i] = names[t[1]]
	}
	return ret
}