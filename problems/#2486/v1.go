func appendCharacters(s string, t string) int {
	n, i := len(t), 0
	for _, c := range s {
		if i == n {
			break
		}
		if byte(c) == t[i] {
			i++
		}
	}
	return n - i
}