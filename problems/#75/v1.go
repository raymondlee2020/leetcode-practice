func sortColors(nums []int) {
	cnt, i := make([]int, 3), 0
	for _, num := range nums {
		cnt[num]++
	}
	for n, c := range cnt {
		for ; c > 0; c-- {
			nums[i] = n
			i++
		}
	}
}