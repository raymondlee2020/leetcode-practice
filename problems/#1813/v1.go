func areSentencesSimilar(sentence1 string, sentence2 string) bool {
    words1, words2 := strings.Split(sentence1, " "), strings.Split(sentence2, " ")
    if len(words1) > len(words2) {
        words1, words2 = words2, words1
    }
    n, m, w := len(words1), len(words2), len(words2) - len(words1)
    isEqual := func(l, r int) bool {
        i, j := 0, 0
        for ; j < l; i, j = i + 1, j + 1 {
            if words1[i] != words2[j] {
                return false
            }
        }
        j = r
        for ; j < m; i, j = i + 1, j + 1 {
            if words1[i] != words2[j] {
                return false
            }
        }
        return true
    }
    ret := false
    for i := 0; !ret && i <= n; i++ {
        ret = isEqual(i, i + w)
    }
    return ret
}