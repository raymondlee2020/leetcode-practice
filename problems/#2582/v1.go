func passThePillow(n int, time int) int {
	time = time % (2 * (n - 1))
	if time > n-1 {
		time = (2 * (n - 1)) - time
	}
	return time + 1
}