func countMaxOrSubsets(nums []int) int {
    ret, tar, n := 0, 0, len(nums)
    for _, num := range nums {
        tar |= num
    }
    var solve func(i, cur int)
    solve = func(i, cur int) {
        if i == n {
            return
        }
        solve(i + 1, cur)
        nxt := cur | nums[i]
        if nxt == tar {
            ret += int(math.Pow(float64(2), float64(n - i - 1)))
            return
        }
        solve(i + 1, nxt)
    }
    solve(0, 0)
    return ret
}