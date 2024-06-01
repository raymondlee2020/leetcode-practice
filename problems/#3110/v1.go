func scoreOfString(s string) int {
	ret, n := 0, len(s)
	for i := 1; i < n; i++ {
		ret += abs(int(s[i-1]) - int(s[i]))
	}
	return ret
}

func abs(num int) int {
	if num < 0 {
		return -num
	}
	return num
}