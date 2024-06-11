func relativeSortArray(arr1 []int, arr2 []int) []int {
	ret, cnt, tmp := make([]int, 0), make(map[int]int), make([]int, 0)
	for _, num := range arr2 {
		cnt[num] = 0
	}
	for _, num := range arr1 {
		if _, exist := cnt[num]; exist {
			cnt[num]++
		} else {
			tmp = append(tmp, num)
		}
	}
	for _, num := range arr2 {
		for cnt[num] > 0 {
			ret = append(ret, num)
			cnt[num]--
		}
	}
	sort.Ints(tmp)
	ret = append(ret, tmp...)
	return ret
}