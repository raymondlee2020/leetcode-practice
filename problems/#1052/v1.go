func maxSatisfied(customers []int, grumpy []int, minutes int) int {
	ret, cover, unsatisfied, maxUnsatisfied := 0, make([][]int, 0), 0, 0
	for i, customer := range customers {
		if len(cover) > 0 && i-cover[0][0] == minutes {
			unsatisfied -= cover[0][1]
			cover = cover[1:]
		}
		if grumpy[i] > 0 {
			unsatisfied += customer
			cover = append(cover, []int{i, customer})
		} else {
			ret += customer
		}
		maxUnsatisfied = max(maxUnsatisfied, unsatisfied)
	}
	ret += maxUnsatisfied
	return ret
}