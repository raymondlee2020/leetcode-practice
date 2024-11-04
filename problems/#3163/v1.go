func compressedString(word string) string {
    ret, cur, acc := make([]string, 0), rune(word[0]), 0
    for _, c := range word {
        if c != cur || acc == 9 {
            ret = append(ret, fmt.Sprintf("%d%c", acc, cur))
            cur, acc = c, 0
        }
        acc++
    }
    ret = append(ret, fmt.Sprintf("%d%c", acc, cur))
    return strings.Join(ret, "")
}