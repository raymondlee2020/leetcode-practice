func longestSubarray(nums []int, limit int) int {
	ret, n, maxcands, mincands := 0, len(nums), make([]int, 0), make([]int, 0)
	for l, r := 0, 0; r < n; r++ {
		for len(maxcands) > 0 && nums[maxcands[len(maxcands)-1]] <= nums[r] {
			maxcands = maxcands[:len(maxcands)-1]
		}
		maxcands = append(maxcands, r)
		for len(mincands) > 0 && nums[mincands[len(mincands)-1]] >= nums[r] {
			mincands = mincands[:len(mincands)-1]
		}
		mincands = append(mincands, r)
		for nums[maxcands[0]]-nums[mincands[0]] > limit {
			l++
			if maxcands[0] < l {
				maxcands = maxcands[1:]
			}
			if mincands[0] < l {
				mincands = mincands[1:]
			}
		}
		ret = max(ret, r-l+1)
	}
	return ret
}
