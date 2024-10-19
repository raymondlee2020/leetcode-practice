func findKthBit(n int, k int) byte {
    ret, cur := byte('0'), "0"
    for i := 2; i <= n; i++ {
        cur = cur + "1" + reverseStr(invertBitStr(cur))
        if len(cur) >= k {
            ret = cur[k - 1] 
            break
        }
    }
    return ret
}

func invertBitStr(s string) string {
	inverted := []rune(s)
	for i, bit := range inverted {
		if bit == '0' {
			inverted[i] = '1'
		} else if bit == '1' {
			inverted[i] = '0'
		}
	}
	return string(inverted)
}

func reverseStr(s string) string {
	reversed := []rune(s)
	for i, j := 0, len(reversed) - 1; i < j; i, j = i + 1, j - 1 {
		reversed[i], reversed[j] = reversed[j], reversed[i]
	}
	return string(reversed)
}