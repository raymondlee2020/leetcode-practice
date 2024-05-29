func numSteps(s string) int {
	ret, n, carry := 0, len(s), 0
	for i := n - 1; i > 0; i-- {
		if ((int(s[i]) % 2) ^ carry) == 1 {
			carry = 1
			ret++
		}
		ret++
	}
	if carry == 1 {
		ret++
	}
	return ret
}