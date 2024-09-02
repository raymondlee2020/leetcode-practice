func chalkReplacer(chalk []int, k int) int {
    ret, csum := 0, 0
    for _, cost := range chalk {
        csum += cost
    }
    k %= csum
    for i, cost := range chalk {
        if cost > k {
            ret = i
            break
        }
        k -= cost
    }
    return ret
}