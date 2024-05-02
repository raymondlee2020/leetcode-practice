func findMaxK(nums []int) int {
	ret, m := -1, make(map[int]bool)
	for _, num := range nums {
		if _, exist := m[-num]; exist {
			ret = max(ret, abs(num))
		}
		m[num] = true
	}
	return ret
}

func abs(num int) int {
	if num < 0 {
		return -num
	}
	return num
}