func minDays(bloomDay []int, m int, k int) int {
	n, l, r := len(bloomDay), 0, int(1e9)
	if m*k > n {
		return -1
	}
	for l < r {
		mid := l + (r-l)/2
		if canMakeBouquets(bloomDay, mid, m, k) {
			r = mid
		} else {
			l = mid + 1
		}
	}
	return l
}

func canMakeBouquets(bloomDay []int, day int, m int, k int) bool {
	cnt, curr := 0, 0
	for _, d := range bloomDay {
		if d > day {
			curr = 0
			continue
		}
		curr++
		if curr == k {
			cnt++
			curr = 0
		}
	}
	return cnt >= m
}