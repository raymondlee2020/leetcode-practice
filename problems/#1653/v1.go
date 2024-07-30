func minimumDeletions(s string) int {
	acnt, bcnt := 0, 0
	for _, c := range s {
		if c == 'a' {
			acnt++
		}
	}
	ret := acnt
	for _, c := range s {
		if c == 'a' {
			acnt--
		} else {
			bcnt++
		}
		ret = min(ret, acnt+bcnt)
	}
	return ret
}