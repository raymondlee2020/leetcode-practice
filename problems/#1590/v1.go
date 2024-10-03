func minSubarray(nums []int, p int) int {
    ret, presum, total, m := len(nums), 0, 0, make(map[int]int)
    for _, num := range nums {
        total += num
    }
    tr := total % p
    if tr == 0 {
        return 0
    }
    m[0] = -1
    for i, num := range nums {
        presum += num
        psr := presum % p
        if idx, exist := m[(psr + p - tr) % p]; exist {
            ret = min(ret, i - idx)
        }
        m[psr] = i
    }
    if ret == len(nums) {
        return -1
    }
    return ret
}