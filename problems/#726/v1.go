func countOfAtoms(formula string) string {
	ret, cnt, stk, r, n := "", make(map[string]int), make([]int, 0), 1, len(formula)
	for i := n - 1; i >= 0; i-- {
		if formula[i] == '(' {
			r = stk[len(stk)-1]
			stk = stk[:len(stk)-1]
			continue
		}
		cntPart := 1
		if c := formula[i]; c >= '0' && c <= '9' {
			tmp := ""
			for ; c >= '0' && c <= '9'; c, i = formula[i-1], i-1 {
				tmp = string(c) + tmp
			}
			cntPart, _ = strconv.Atoi(tmp)
		}
		if formula[i] == ')' {
			stk = append(stk, r)
			r *= cntPart
		} else {
			namePart := ""
			for c := formula[i]; c >= 'a' && c <= 'z'; c, i = formula[i-1], i-1 {
				namePart = string(c) + namePart
			}
			namePart = string(formula[i]) + namePart
			cnt[namePart] += cntPart * r
		}
	}
	tmp := make([]string, 0)
	for atom, _ := range cnt {
		tmp = append(tmp, atom)
	}
	sort.Strings(tmp)
	for _, atom := range tmp {
		if cnt[atom] == 1 {
			ret += atom
		} else {
			ret += fmt.Sprintf("%s%d", atom, cnt[atom])
		}
	}
	return ret
}