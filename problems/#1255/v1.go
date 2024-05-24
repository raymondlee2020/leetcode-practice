func maxScoreWords(words []string, letters []byte, score []int) int {
	const ACODE = int('a')
	ws, lcnt := make([]int, len(words)), make(map[byte]int)
	for i, word := range words {
		for _, c := range word {
			ws[i] += score[int(c)-ACODE]
		}
	}
	for _, letter := range letters {
		lcnt[letter]++
	}
	return solve(ws, lcnt, words, 0, 0)
}

func solve(ws []int, lcnt map[byte]int, words []string, i int, curr int) int {
	if i == len(words) {
		return curr
	}
	ret := 0
	if use(lcnt, words[i]) {
		ret = solve(ws, lcnt, words, i+1, curr+ws[i])
		unuse(lcnt, words[i])
	}
	ret = max(ret, solve(ws, lcnt, words, i+1, curr))
	return ret
}

func use(lcnt map[byte]int, word string) bool {
	success := true
	for _, c := range word {
		lcnt[byte(c)]--
		if lcnt[byte(c)] < 0 {
			success = false
		}
	}
	if !success {
		unuse(lcnt, word)
	}
	return success
}

func unuse(lcnt map[byte]int, word string) {
	for _, c := range word {
		lcnt[byte(c)]++
	}
}