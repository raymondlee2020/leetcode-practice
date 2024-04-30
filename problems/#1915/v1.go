func wonderfulSubstrings(word string) int64 {
	ret, cnt, curr := 0, make(map[int]int), 0
	cnt[0]++
	for _, char := range word {
		// curr string ends with char
		curr ^= (1 << int(char-'a'))
		// the diff of two same bitmasks must be all even case
		if n, exist := cnt[curr]; exist && n > 0 {
			ret += n
		}
		for i := range 10 {
			tmp := curr ^ (1 << i)
			if n, exist := cnt[tmp]; exist && n > 0 {
				// exist prefix xor curr is only one odd case
				ret += n
			}
		}
		cnt[curr]++
	}
	return int64(ret)
}