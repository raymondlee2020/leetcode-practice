func lemonadeChange(bills []int) bool {
	cnt := make(map[int]int)
	for _, bill := range bills {
		if bill == 10 {
			if cnt[5] > 0 {
				cnt[5]--
			} else {
				return false
			}
		} else if bill == 20 {
			if cnt[10] > 0 && cnt[5] > 0 {
				cnt[10]--
				cnt[5]--
			} else if cnt[5] > 2 {
				cnt[5] -= 3
			} else {
				return false
			}
		}
		cnt[bill]++
	}
	return true
}