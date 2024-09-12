func countConsistentStrings(allowed string, words []string) int {
    ret, m := 0, make(map[rune]bool)
    for _, c := range allowed {
        m[c] = true
    }
    for _, word := range words {
        isConsistent := true
        for _, c := range word {
            isConsistent = isConsistent && m[c]
        }
        if isConsistent {
            ret++
        }
    }
    return ret
}