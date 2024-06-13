func minMovesToSeat(seats []int, students []int) int {
	ret, n := 0, len(seats)
	sort.Ints(seats)
	sort.Ints(students)
	for i := range n {
		ret += abs(seats[i] - students[i])
	}
	return ret
}

func abs(num int) int {
	if num < 0 {
		return -num
	}
	return num
}