func subsetXORSum(nums []int) int {
	ret, curr := 0, 0
	solve(&ret, nums, 0, &curr)
	return ret
}

func solve(ret *int, nums []int, i int, curr *int) {
	if i == len(nums) {
		*ret += *curr
		return
	}
	*curr ^= nums[i]
	solve(ret, nums, i+1, curr)
	*curr ^= nums[i]
	solve(ret, nums, i+1, curr)
}