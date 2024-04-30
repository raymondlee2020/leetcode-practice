func minOperations(nums []int, k int) int {
	ret := 0
	for _, num := range nums {
		k ^= num
	}
	for k > 0 {
		ret += k & 1
		k /= 2
	}
	return ret
}