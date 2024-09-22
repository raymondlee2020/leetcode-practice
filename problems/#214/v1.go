func shortestPalindrome(s string) string {
    n := len(s)
	if n == 0 {
		return s
	}
	rev := reverse(s)
	lps := buildKMPTable(s + "#" + rev)
	return rev[:n - lps[len(lps) - 1]] + s
}

func reverse(s string) string {
	tmp := []rune(s)
	for i, j := 0, len(s) - 1; i < j; i, j = i + 1, j - 1 {
		tmp[i], tmp[j] = tmp[j], tmp[i]
	}
	return string(tmp)
}

func buildKMPTable(pattern string) []int {
	n := len(pattern)
	lps := make([]int, n) // longest prefix suffix array
	length, i := 0, 1
	for i < n {
		if pattern[i] == pattern[length] {
			length++
			lps[i] = length
			i++
		} else {
			if length != 0 {
				length = lps[length - 1]
			} else {
				lps[i] = 0
				i++
			}
		}
	}
	return lps
}