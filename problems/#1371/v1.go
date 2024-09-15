func findTheLongestSubstring(s string) int {
    ret, m, curr := 0, make(map[int]int), 0
    m[0] = -1
    for i, c := range s {
        curr ^= bitOf(c)
        if _, exist := m[curr]; !exist {
            m[curr] = i
        }
        ret = max(ret, i - m[curr])
    }
    return ret
}

func bitOf(c rune) int {
    return (1 << (strings.Index("aeiou", string(c)) + 1)) >> 1
}