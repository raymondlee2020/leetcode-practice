func maxProfitAssignment(difficulty []int, profit []int, worker []int) int {
	ret, n, maxProfit := 0, len(difficulty), 0
	jobs := make([][]int, n)
	for i := range n {
		jobs[i] = []int{difficulty[i], profit[i]}
	}
	sort.Slice(jobs, func(i, j int) bool {
		if jobs[i][0] == jobs[j][0] {
			return jobs[i][1] > jobs[j][1]
		}
		return jobs[i][0] < jobs[j][0]
	})
	for i := range n {
		maxProfit = max(maxProfit, jobs[i][1])
		jobs[i][1] = maxProfit
	}
	for _, ability := range worker {
		ret += binarySearch(jobs, ability)
	}
	return ret
}

func binarySearch(jobs [][]int, ability int) int {
	l, r := 0, len(jobs)
	var mid int
	for l < r {
		mid = l + (r-l)/2
		if jobs[mid][0] > ability {
			r = mid
		} else if jobs[mid][0] < ability {
			l = mid + 1
		} else {
			l = mid + 1
			break
		}
	}
	if l == 0 {
		return 0
	}
	return jobs[l-1][1]
}