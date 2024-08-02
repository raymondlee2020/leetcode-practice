func minSwaps(nums []int) int {
	cnt, ret, n := 0, 0, len(nums)
	for _, num := range nums {
		if num == 1 {
			cnt++
		}
	}
	if cnt == 0 {
		return 0
	}
	for i := n - cnt; i < n; i++ {
		if nums[i] == 0 {
			ret++
		}
	}
	for l, r, curr := len(nums)-cnt, 0, ret; r < n; l, r = (l+1)%n, r+1 {
		if nums[l] == 0 {
			curr--
		}
		if nums[r] == 0 {
			curr++
		}
		ret = min(ret, curr)
	}
	return ret
}