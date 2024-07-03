func minDifference(nums []int) int {
	if len(nums) < 5 {
		return 0
	}
	ret, mins, maxs := math.MaxInt, []int{math.MaxInt, math.MaxInt, math.MaxInt, math.MaxInt}, []int{-math.MaxInt, -math.MaxInt, -math.MaxInt, -math.MaxInt}
	for _, num := range nums {
		if num > maxs[0] {
			for i := 1; i < 4; i++ {
				if maxs[i] > num {
					maxs[i-1] = num
					break
				}
				maxs[i], maxs[i-1] = maxs[i-1], maxs[i]
			}
			if num > maxs[3] {
				maxs[3] = num
			}
		}
		if num < mins[0] {
			for i := 1; i < 4; i++ {
				if mins[i] < num {
					mins[i-1] = num
					break
				}
				mins[i], mins[i-1] = mins[i-1], mins[i]
			}
			if num < mins[3] {
				mins[3] = num
			}
		}
	}
	for i := 0; i < 4; i++ {
		ret = min(ret, maxs[3-i]-mins[i])
	}
	return ret
}