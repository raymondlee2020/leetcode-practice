func commonChars(words []string) []string {
	ret, m, tmp := make([]string, 0), make([]int, 26), make([]int, 26)
	for i := range m {
		m[i] = math.MaxUint8
	}
	for _, word := range words {
		for _, c := range word {
			tmp[c-'a']++
		}
		for i := range 26 {
			m[i] = min(m[i], tmp[i])
			tmp[i] = 0
		}
	}
	for i := range 26 {
		for j := 0; j < m[i]; j++ {
			ret = append(ret, string('a'+i))
		}
	}
	return ret
}