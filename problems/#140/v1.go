func wordBreak(s string, wordDict []string) []string {
	ret, wd, curr := make([]string, 0), make(map[string]bool), make([]string, 0)
	for _, word := range wordDict {
		wd[word] = true
	}
	solve(&ret, wd, &curr, 0, s)
	return ret
}

func solve(ret *[]string, wd map[string]bool, curr *[]string, l int, s string) {
	n := len(s)
	if l == n {
		*ret = append(*ret, strings.Join(*curr, " "))
		return
	}
	for r := l + 1; r <= n; r++ {
		tmp := s[l:r]
		if wd[tmp] {
			*curr = append(*curr, tmp)
			solve(ret, wd, curr, r, s)
			*curr = (*curr)[:len(*curr)-1]
		}
	}
}