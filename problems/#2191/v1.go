func sortJumbled(mapping []int, nums []int) []int {
	m, idx := make(map[int]int), make(map[int]int)
	for i, num := range nums {
		idx[nums[i]] = i
		m[nums[i]] = 0
		if num == 0 {
			m[0] = mapping[0]
			continue
		}
		d := 1
		for num > 0 {
			m[nums[i]] += mapping[(num%10)] * d
			num /= 10
			d *= 10
		}
	}
	sort.Slice(nums, func(i, j int) bool {
		if m[nums[i]] == m[nums[j]] {
			return idx[nums[i]] < idx[nums[j]]
		}
		return m[nums[i]] < m[nums[j]]
	})
	return nums
}