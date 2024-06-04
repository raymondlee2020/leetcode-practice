func longestPalindrome(s string) int {
	m := make(map[rune]bool)
	for _, c := range s {
		if _, exist := m[c]; exist {
			delete(m, c)
		} else {
			m[c] = true
		}
	}
	return min(len(s)-len(m)+1, len(s))
}