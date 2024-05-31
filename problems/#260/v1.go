func singleNumber(nums []int) []int {
	ret, m := make([]int, 0), make(map[int]bool)
	for _, num := range nums {
		if _, exist := m[num]; exist {
			delete(m, num)
		} else {
			m[num] = true
		}
	}
	for k, _ := range m {
		ret = append(ret, k)
	}
	return ret
}