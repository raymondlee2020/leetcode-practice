func minBitFlips(start int, goal int) int {
    ret, diff := 0, start ^ goal
    for diff > 0 {
        if diff & 1 == 1 {
            ret++
        }
        diff >>= 1
    }
    return ret
}