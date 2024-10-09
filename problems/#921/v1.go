func minAddToMakeValid(s string) int {
    ret, acc := 0, 0
    for _, c := range s {
        if c == '(' {
            acc++
        } else {
            if acc > 0 {
                acc--
            } else {
                ret++
            }
        }
    }
    ret += acc
    return ret
}