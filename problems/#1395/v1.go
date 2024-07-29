func numTeams(rating []int) int {
	ret, n := 0, len(rating)
	for mid := 1; mid < n-1; mid++ {
		leftSmallerCnt, rightLargerCnt := 0, 0
		for i := range n {
			if i < mid && rating[i] < rating[mid] {
				leftSmallerCnt++
			}
			if i > mid && rating[i] > rating[mid] {
				rightLargerCnt++
			}
		}
		ret += leftSmallerCnt * rightLargerCnt
		ret += (mid - leftSmallerCnt) * (n - 1 - mid - rightLargerCnt)
	}
	return ret
}