func maxDistance(position []int, m int) int {
	sort.Ints(position)
	l, r := 0, position[len(position)-1]-position[0]+1
	for l < r {
		mid := l + (r-l)/2
		if canDistributeBalls(position, m, mid) {
			l = mid + 1
		} else {
			r = mid
		}
	}
	return l - 1
}

func canDistributeBalls(position []int, m int, force int) bool {
	cnt, start := 0, 0
	for i, p := range position {
		if p-position[start] >= force {
			cnt++
			start = i
		}
	}
	return cnt+1 >= m
}