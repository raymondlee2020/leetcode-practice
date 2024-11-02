func isCircularSentence(sentence string) bool {
    for i, c := range sentence {
        if c == ' ' && sentence[i - 1] != sentence[i + 1] {
            return false
        }
    }
    return sentence[0] == sentence[len(sentence) - 1]
}