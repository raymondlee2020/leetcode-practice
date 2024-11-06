func canSortArray(nums []int) bool {
    prevMax, currMin, currMax, currSB := -1, 0, -1, 0
    for _, num := range nums {
        iSB := setBits(num)
        if iSB == currSB {
            currMin, currMax = min(currMin, num), max(currMax, num)
        } else {
            if prevMax != -1 && prevMax > currMin {
                return false
            }
            prevMax, currMin, currMax, currSB = currMax, num, num, iSB
        }
    }
    return prevMax < currMin
}

func setBits(num int) int {
    ret := 0
	for ; num > 0; num >>= 1 {
		ret += num & 1
	}
	return ret
}