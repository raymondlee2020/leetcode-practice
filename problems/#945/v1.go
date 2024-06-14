func minIncrementForUnique(nums []int) int {
	ret, avail := 0, 0
	sort.Ints(nums)
	for _, num := range nums {
		ret += max(avail-num, 0)
		avail = max(avail, num) + 1
	}
	return ret
}