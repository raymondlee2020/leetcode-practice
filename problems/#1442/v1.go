func countTriplets(arr []int) int {
	arr = append([]int{0}, arr...)
	ret, n := 0, len(arr)
	for i := 1; i < n; i++ {
		arr[i] ^= arr[i-1]
	}
	for i := 1; i < n; i++ {
		for j := i + 1; j < n; j++ {
			a := arr[j-1] ^ arr[i-1]
			for k := j; k < n; k++ {
				b := arr[k] ^ arr[j-1]
				if a == b {
					ret++
				}
			}
		}
	}
	return ret
}