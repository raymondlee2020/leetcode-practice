func reversePrefix(word string, ch byte) string {
	ret, n := "", len(word)
	var i int
	for i = 0; i < n; i++ {
		ret = string(word[i]) + ret
		if word[i] == ch {
			i++
			return ret + word[i:]
		}
	}
	return word
}