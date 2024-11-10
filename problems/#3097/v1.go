func minimumSubarrayLength(nums []int, k int) int {
    ret, cur, bitCnt, n := math.MaxInt, 0, make([]int, 32), len(nums)
    for l, r := 0, 0; r < n; r++ {
        for i, num := 0, nums[r]; i < 32 && num > 0; i, num = i + 1, num >> 1 {
            if (num & 1) == 1 {
                cur |= (1 << i)
                bitCnt[i]++
            }
        }
        if cur < k {
            continue
        }
        for ; l <= r && cur >= k; l++ {
            ret = min(ret, r - l + 1)
            for i, num := 0, nums[l]; i < 32 && num > 0; i, num = i + 1, num >> 1 {
                if (num & 1) == 1 {
                    bitCnt[i]--
                    if bitCnt[i] == 0 {
                        cur ^= (1 << i)
                    }
                }
            }
        }
    }
    if ret == math.MaxInt {
        return -1
    }
    return ret
}