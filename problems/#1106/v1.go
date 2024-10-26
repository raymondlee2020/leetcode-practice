func parseBoolExpr(expression string) bool {
    stk := []rune{}
    for _, c := range expression {
        if c != ')' && c != ',' {
            stk = append(stk, c)
        } else if c == ')' {
            bs := []bool{}
            for len(stk) > 0 && stk[len(stk) - 1] != '(' {
                b := stk[len(stk) - 1]
                stk = stk[:len(stk) - 1]
                bs = append(bs, b == 't')
            }
            stk = stk[:len(stk) - 1]
            if len(stk) > 0 {
                op := stk[len(stk) - 1]
                stk = stk[:len(stk) - 1]
                v := bs[0]
                if op == '&' {
                    for _, b := range bs {
                        v = v && b
                    }
                } else if op == '|' {
                    for _, b := range bs {
                        v = v || b
                    }
                } else {
                    v = !v
                }
                if v {
                    stk = append(stk, 't')
                } else {
                    stk = append(stk, 'f')
                }
            }
        }
    }

    return stk[len(stk)-1] == 't'
}