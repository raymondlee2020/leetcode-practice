func tribonacci(n int) int {
	if n == 0 {
		return 0
	}
	if n < 3 {
		return 1
	}
	t0, t1, t2 := 0, 1, 1
	for ; n > 2; n-- {
		t0, t1, t2 = t1, t2, (t0 + t1 + t2)
	}
	return t2
}