func minimumMountainRemovals(nums []int) int {
    lmax, n := 0, len(nums)
    longestMonotonic := func() []int {
        ret, ends := make([]int, n), make([]int, 1)
        ret[0], ends[0] = 1, nums[0]
        for i := 1; i < n; i++ {
            if nums[i] > ends[len(ends) - 1] {
                ends = append(ends, nums[i])
                ret[i] = len(ends)
            } else {
                k := -1
                for j := len(ends) - 2; j >= 0; j-- {
                    if nums[i] > ends[j] {
                        k = j
                        break
                    }
                }
                ret[i], ends[k + 1] = k + 2, nums[i]
            }
        }
        return ret
    }
    up := longestMonotonic()
    for l, r := 0, n - 1; l < r; l, r = l + 1, r - 1 {
        nums[l], nums[r] = nums[r], nums[l]
    }
    down := longestMonotonic()
    for i := range n {
        if up[i] == 1 || down[n - 1 - i] == 1 {
            continue
        }
        lmax = max(lmax, up[i] + down[n - 1 - i] - 1)
    }
    return n - lmax
}