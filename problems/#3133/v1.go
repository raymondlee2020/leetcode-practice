func minEnd(n int, x int) int64 {
    ret, n := int64(x), n - 1
    for i := 0; n > 0; i++ {
        if (ret & (1 << i)) == 0 {
            if (n & 1) == 1 {
                ret += (1 << i)
            }
            n >>= 1
        }
    }
    return ret
}