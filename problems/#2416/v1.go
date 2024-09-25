func sumPrefixScores(words []string) []int {
    ret, score := make([]int, len(words)), make(map[string]int)
    for _, word := range words {
        n := len(word)
        for i := 1; i <= n; i++ {
            score[word[:i]]++
        }
    }
    for i, word := range words {
        n := len(word)
        for j := 1; j <= n; j++ {
            ret[i] += score[word[:j]]
        }
    }
    return ret
}