func rangeSum(nums []int, n int, left int, right int) int {
	ret, tmp, MOD, idx := 0, make([]int, n*(n+1)/2), int(1e9+7), 0
	for i := 0; i < n; i++ {
		acc := 0
		for j := i; j < n; j++ {
			acc += nums[j]
			tmp[idx] = acc
			idx++
		}
	}
	sort.Ints(tmp)
	for i := left - 1; i < right; i++ {
		ret = (ret + tmp[i]) % MOD
	}
	return ret
}