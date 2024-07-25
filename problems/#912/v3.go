func sortArray(nums []int) []int {
	n := len(nums)
	for i := n / 2; i >= 0; i-- {
		heapify(&nums, n, i)
	}
	for i := n - 1; i >= 0; i-- {
		nums[0], nums[i] = nums[i], nums[0]
		heapify(&nums, i, 0)
	}
	return nums
}

func heapify(nums *[]int, bound int, parent int) {
	l, r, maxidx := 2*parent+1, 2*parent+2, parent
	if l < bound && (*nums)[l] > (*nums)[maxidx] {
		maxidx = l
	}
	if r < bound && (*nums)[r] > (*nums)[maxidx] {
		maxidx = r
	}
	if maxidx != parent {
		(*nums)[maxidx], (*nums)[parent] = (*nums)[parent], (*nums)[maxidx]
		heapify(nums, bound, maxidx)
	}
}