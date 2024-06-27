func findCenter(edges [][]int) int {
	ret, cnt := 0, make(map[int]int)
	for _, edge := range edges {
		cnt[edge[0]]++
		cnt[edge[1]]++
	}
	for k, v := range cnt {
		if v > cnt[ret] {
			ret = k
		}
	}
	return ret
}