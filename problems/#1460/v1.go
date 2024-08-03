func canBeEqual(target []int, arr []int) bool {
	cnt := make(map[int]int)
	for _, num := range target {
		cnt[num]++
	}
	for _, num := range arr {
		cnt[num]--
		if cnt[num] < 0 {
			return false
		}
	}
	return true
}