func longestDiverseString(a int, b int, c int) string {
	ret := ""
	for i := 0; a > 0 || b > 0 || c > 0; i++ {
		banA, banB, banC := false, false, false
		if i >= 2 && ret[i - 1] == ret[i - 2] {
			banA = ret[i - 1] == 'a'
			banB = ret[i - 1] == 'b'
			banC = ret[i - 1] == 'c'
		}
		char := getNxtChar(a, b, c, banA, banB, banC)
		if char == 0 {
			break
		} else {
			ret += string(char)
			if char == 'a' {
				a--
			} else if char == 'b' {
				b--
			} else {
				c--
			}
		}
	}
	return ret
}

func getNxtChar(a, b, c int, banA, banB, banC bool) byte {
	if banA {
		a = 0
	}
	if banB {
		b = 0
	}
	if banC {
		c = 0
	}
	if a >= b && a >= c && a > 0 {
		return 'a'
	} else if b >= a && b >= c && b > 0 {
		return 'b'
    } else if c > 0 {
		return 'c'
	}
	return 0
}