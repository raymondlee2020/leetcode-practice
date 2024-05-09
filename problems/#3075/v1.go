func maximumHappinessSum(happiness []int, k int) int64 {
	var ret int64 = 0
	sort.Sort(sort.Reverse(sort.IntSlice(happiness)))
	for i := range k {
		ret += int64(max(happiness[i]-i, 0))
	}
	return ret
}