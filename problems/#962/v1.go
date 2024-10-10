func maxWidthRamp(nums []int) int {
    ret, n, stk := 0, len(nums), make([]int, 0)
    for i, num := range nums {
        if m := len(stk); m == 0 || nums[stk[m - 1]] > num {
            stk = append(stk, i)
        }
    }
    for i := n - 1; i > ret; i-- {
        for m := len(stk); m > 0 && nums[i] >= nums[stk[m - 1]]; m-- {
            ret = max(ret, i - stk[m - 1])
            stk = stk[:m - 1]
        }
    }
    return ret
}