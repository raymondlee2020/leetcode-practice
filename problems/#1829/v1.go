func getMaximumXor(nums []int, maximumBit int) []int {
    n, maxBound, acc := len(nums), (1 << maximumBit) - 1, 0
    ret := make([]int, n)
    for i, num := range nums {
        acc ^= num
        ret[n - 1 - i] = acc ^ maxBound
    }
    return ret
}