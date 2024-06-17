func judgeSquareSum(c int) bool {
	n, m := int(math.Ceil(math.Sqrt(float64(c))))+1, make(map[int]bool)
	for i := range n {
		sq := int(math.Pow(float64(i), 2))
		m[sq] = true
		if _, exist := m[c-sq]; exist {
			return true
		}
	}
	return false
}