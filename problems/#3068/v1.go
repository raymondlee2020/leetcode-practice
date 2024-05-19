func maximumValueSum(nums []int, k int, edges [][]int) int64 {
	var xored int
	ret, minDiff, ops := int64(0), math.MaxInt, 0
	for _, num := range nums {
		xored = num ^ k
		if xored > num {
			ops ^= 1
			ret += int64(xored)
			minDiff = min(minDiff, xored-num)
		} else {
			ret += int64(num)
			minDiff = min(minDiff, num-xored)
		}
	}
	return ret - int64(ops*minDiff)
}