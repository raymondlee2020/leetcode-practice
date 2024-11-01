func makeFancyString(s string) string {
    ret, curr, acc := make([]rune, 0), 'A', 0
    for _, c := range s {
        if c != curr {
            curr, acc = c, 0
        } else if acc == 2 {
            continue
        }
        acc++
        ret = append(ret, c)
    }
    return string(ret)
}