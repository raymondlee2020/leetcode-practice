func isNStraightHand(hand []int, groupSize int) bool {
	n := len(hand)
	if n%groupSize != 0 {
		return false
	}
	sort.Ints(hand)
	cnt, curr, start := make([][]int, 0), hand[0], 0
	for i, num := range hand {
		if num != hand[start] {
			cnt = append(cnt, []int{curr, i - start})
			curr, start = num, i
		}
	}
	cnt = append(cnt, []int{curr, n - start})
	m := len(cnt)
	for i, c := range cnt {
		if c[1] == 0 {
			continue
		}
		minus := c[1]
		for j := range groupSize {
			if i+j == m {
				return false
			}
			tmp := cnt[i+j]
			if (tmp[0]-c[0] != j) || (tmp[1] < minus) {
				return false
			}
			cnt[i+j][1] -= minus
		}
	}
	return true
}