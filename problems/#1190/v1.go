func reverseParentheses(s string) string {
	n := len(s)
	ret, stk, portal := "", make([]int, 0), make([]int, n)
	for i, c := range s {
		if c == '(' {
			stk = append(stk, i)
		} else if c == ')' {
			m := len(stk)
			j := stk[m-1]
			stk = stk[:m-1]
			portal[i], portal[j] = j, i
		}
	}
	for i, d := 0, 1; i < n; i += d {
		if s[i] == '(' || s[i] == ')' {
			i, d = portal[i], -d
		} else {
			ret += string(s[i])
		}
	}
	return ret
}