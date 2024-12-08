func maxTwoEvents(events [][]int) int {
    sort.Slice(events, func(i, j int) bool {
        return events[i][1] < events[j][1]
    })
    n := len(events)
    preMax := make([]int, n)
    preMax[0] = events[0][2]
    for i := 1; i < n; i++ {
        preMax[i] = max(preMax[i - 1], events[i][2])
    }
    ret := preMax[n - 1]
    for _, event := range events {
        s, val := event[0], event[2]
        if s <= events[0][1] {
            continue
        }
        l, r := 0, n - 1
        for l <= r {
            mid := l + (r - l) / 2
            if events[mid][1] < s {
                l = mid + 1
            } else {
                r = mid - 1
            }
        }
        ret = max(ret, val + preMax[r])
    }
    return ret
}