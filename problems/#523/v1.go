func checkSubarraySum(nums []int, k int) bool {
	m, acc := make(map[int]int), 0
	m[0] = -1
	for i, num := range nums {
		acc = (acc + num) % k
		if j, exist := m[acc]; exist {
			if i-j > 1 {
				return true
			}
		} else {
			m[acc] = i
		}
	}
	return false
}