func subsets(nums []int) [][]int {
	retLen := powInt(2, len(nums))
	ret := make([][]int, retLen)
	for i := range retLen {
		ret[i] = make([]int, 0)
		for j, num := range nums {
			if ((i >> j) & 1) == 1 {
				ret[i] = append(ret[i], num)
			}
		}
	}
	return ret
}

func powInt(x, y int) int {
	return int(math.Pow(float64(x), float64(y)))
}