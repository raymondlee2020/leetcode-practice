func minLength(s string) int {
    stk := make([]rune, 0)
    for _, c := range s {
        stklen := len(stk)
        if stklen > 0 && ((stk[stklen - 1] == 'A' && c == 'B') || (stk[stklen - 1] == 'C' && c == 'D')) {
            stk = stk[:stklen - 1]
        } else {
            stk = append(stk, c)
        }
    }
    return len(stk)
}