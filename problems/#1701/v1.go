func averageWaitingTime(customers [][]int) float64 {
	ret, nextIdle := 0, 0
	for _, customer := range customers {
		if customer[0] >= nextIdle {
			nextIdle = customer[0] + customer[1]
			ret += customer[1]
		} else {
			nextIdle += customer[1]
			ret += (nextIdle - customer[0])
		}
	}
	return float64(ret) / float64(len(customers))
}