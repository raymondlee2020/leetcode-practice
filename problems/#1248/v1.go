func numberOfSubarrays(nums []int, k int) int {
	ret, n := 0, len(nums)
	ll, l := -1, nextOddIdx(nums, -1)
	var r, rr int
	for r = l; k > 1; k-- {
		r = nextOddIdx(nums, r)
		if r == n {
			return 0
		}
	}
	for rr = nextOddIdx(nums, r); r < n; ll, l, r, rr = l, nextOddIdx(nums, l), rr, nextOddIdx(nums, rr) {
		ret += (l - ll) * (rr - r)
	}
	return ret
}

func nextOddIdx(nums []int, idx int) int {
	n := len(nums)
	if idx == n {
		return n
	}
	for idx++; idx < n; idx++ {
		if nums[idx]%2 == 1 {
			break
		}
	}
	return idx
}