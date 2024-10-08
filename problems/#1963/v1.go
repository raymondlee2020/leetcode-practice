func minSwaps(s string) int {
    cnt, maxcnt := 0, 0
    for _, c := range s {
        if c == ']' {
            cnt++
            maxcnt = max(maxcnt, cnt)
        } else {
            cnt--
        }
    }
    return (maxcnt + 1) / 2
}