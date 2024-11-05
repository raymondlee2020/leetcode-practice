func minChanges(s string) int {
    ret, n := 0, len(s)
    for i := 0; i < n; i += 2 {
        if s[i] != s[i + 1] {
            ret++
        }
    }
    return ret
}