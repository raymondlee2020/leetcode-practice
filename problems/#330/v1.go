func minPatches(nums []int, n int) int {
	ret, target, pv, m := 0, 1, 0, len(nums)
	for target <= n {
		if pv < m && nums[pv] <= target {
			target += nums[pv]
			pv++
		} else {
			target *= 2
			ret++
		}
	}
	return ret
}