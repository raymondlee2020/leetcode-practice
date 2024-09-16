func findMinDifference(timePoints []string) int {
    ret, n := math.MaxInt, len(timePoints)
    sort.Strings(timePoints)
    prev := minutes(timePoints[0])
    for i := 1; i < n; i++ {
        curr := minutes(timePoints[i])
        ret = min(ret, curr - prev)
        ret = min(ret, prev + 1440 - curr)
        prev = curr
    }
    ret = min(ret, minutes(timePoints[0]) + 1440 - prev)
    return ret
}

func minutes(s string) int {
    hh, _ := strconv.Atoi(s[0:2])
    mm, _ := strconv.Atoi(s[3:])
    return hh * 60 + mm
}