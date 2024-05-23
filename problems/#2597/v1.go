func beautifulSubsets(nums []int, k int) int {
	ret, hashSet := 0, make(map[int]int)
	solve(&ret, hashSet, &nums, k, 0)
	return ret - 1
}

func solve(ret *int, hashSet map[int]int, nums *[]int, k int, i int) {
	n := len(*nums)
	if i == n {
		(*ret)++
		return
	}
	if hashSet[(*nums)[i]-k] == 0 && hashSet[(*nums)[i]+k] == 0 {
		hashSet[(*nums)[i]]++
		solve(ret, hashSet, nums, k, i+1)
		hashSet[(*nums)[i]]--
	}
	solve(ret, hashSet, nums, k, i+1)
}