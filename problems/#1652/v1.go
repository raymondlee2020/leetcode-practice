func decrypt(code []int, k int) []int {
    ret := make([]int, len(code))
    if k > 0 {
        cur, n := 0, len(code)
        for i := 0; i < k; i++ {
            cur += code[i]
        }
        for i, c := range code {
            cur = cur - c + code[(i + k) % n]
            ret[i] = cur
        }
    } else if  k < 0 {
        cur, n := 0, len(code)
        for i := n - 1; i > n - 1 + k; i-- {
            cur += code[i]
        }
        for i, c := range code {
            ret[i] = cur
            cur = cur + c - code[(i + k + n) % n]
        }
    }
    return ret
}