func addSpaces(s string, spaces []int) string {
    n := len(s) + len(spaces)
    ret, ri, si := make([]byte, n), 0, 0
    for _, space := range spaces {
        for ; si < space; ri, si = ri + 1, si + 1 {
            ret[ri] = s[si]
        }
        ret[ri] = ' '
        ri++
    }
    for ; ri < n; ri, si = ri + 1, si + 1 {
        ret[ri] = s[si]
    }
    return string(ret)
}