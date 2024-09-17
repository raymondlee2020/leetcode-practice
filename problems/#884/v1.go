func uncommonFromSentences(s1 string, s2 string) []string {
    ret, m, ws1, ws2 := make([]string, 0), make(map[string]int), strings.Split(s1, " "), strings.Split(s2, " ")
    for _, w := range ws1 {
        m[w]++
    }
    for _, w := range ws2 {
        m[w]++
    }
    for w, cnt := range m {
        if cnt == 1 {
            ret = append(ret, w)
        }
    }
    return ret
}