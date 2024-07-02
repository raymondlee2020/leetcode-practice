func intersect(nums1 []int, nums2 []int) []int {
	ret, m := make([]int, 0), make(map[int]int)
	for _, num := range nums1 {
		m[num]++
	}
	for _, num := range nums2 {
		if m[num] > 0 {
			ret = append(ret, num)
			m[num]--
		}
	}
	return ret
}