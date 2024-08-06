func minimumPushes(word string) int {
	ret, cnt := 0, make([]int, 26)
	for _, c := range word {
		cnt[c-'a']++
	}
	sort.Sort(sort.Reverse(sort.IntSlice(cnt)))
	for i, c := range cnt {
		if c == 0 {
			break
		}
		ret += c * (i/8 + 1)
	}
	return ret
}