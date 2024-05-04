func numRescueBoats(people []int, limit int) int {
	ret, l, r := 0, 0, len(people)-1
	sort.Ints(people)
	for l < r {
		if people[l]+people[r] <= limit {
			l++
		}
		ret, r = ret+1, r-1
	}
	if l == r {
		ret++
	}
	return ret
}