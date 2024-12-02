func isPrefixOfWord(sentence string, searchWord string) int {
    ret, n := -1, len(sentence)
    for wi, ci := 1, 0; ci < n; wi, ci = wi + 1, ci + 1 {
        isPrefix := true
        for _, c := range searchWord {
            if ci == n || sentence[ci] != byte(c) {
                isPrefix = false
                break
            }
            ci++
        }
        if isPrefix {
            ret = wi
            break
        }
        for ci < n && sentence[ci] != ' ' {
            ci++
        }
    }
    return ret
}