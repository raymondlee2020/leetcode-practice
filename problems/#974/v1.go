func subarraysDivByK(nums []int, k int) int {
	ret, cnt, acc := 0, make(map[int]int), 0
	cnt[0] = 1
	for _, num := range nums {
		acc = (acc + num) % k
		if acc < 0 {
			acc += k
		}
		cnt[acc]++
	}
	for _, v := range cnt {
		ret += v * (v - 1) / 2
	}
	return ret
}