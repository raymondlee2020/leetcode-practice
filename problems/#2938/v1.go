func minimumSteps(s string) int64 {
    ret, l, r := int64(0), 0, len(s) - 1
    for l < r {
        for l < r && s[l] != '1' {
            l++
        }
        for l < r && s[r] != '0' {
            r--
        }
        if r < l {
            break
        }
        ret += int64(r - l)
        l++
        r--
    }
    return ret
}