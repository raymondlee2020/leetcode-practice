func resultsArray(nums []int, k int) []int {
    if k == 1 {
        return nums
    }
    n := len(nums)
    ret, l, r := make([]int, n - k + 1), 0, 1
    for ; r < k - 1; r++ {
        if nums[r] - nums[r - 1] != 1 {
            l = r
        }
    }
    for ; r < n; r++ {
        if nums[r] - nums[r - 1] != 1 {
            l = r
        }
        ret[r + 1 - k] = -1
        if r - l + 1 >= k {
            ret[r + 1 - k] = nums[r]
        }
    }
    return ret
}