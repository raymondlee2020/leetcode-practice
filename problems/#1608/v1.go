func specialArray(nums []int) int {
	sort.Sort(sort.Reverse(sort.IntSlice(nums)))
	for i, num := range nums {
		if i > num {
			return i
		}
		if i+1 > num {
			return -1
		}
	}
	return len(nums)
}