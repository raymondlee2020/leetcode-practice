func maximumBeauty(nums []int, k int) int {
    ret, minNum, maxNum, cnt := 0, math.MaxInt, math.MinInt, make(map[int]int)
    for _, num := range nums {
        minNum = min(minNum, num)
        maxNum = max(maxNum, num)
        cnt[num]++
    }
    k = k * 2
    for i := 0; i <= k; i++ {
        if c, exist := cnt[minNum + i]; exist {
            ret += c
        }
    }
    for i, cur := minNum + (k + 1), ret; i <= maxNum; i++ {
        if c, exist := cnt[i]; exist {
            cur += c
        }
        if c, exist := cnt[i - (k + 1)]; exist {
            cur -= c
        }
        ret = max(ret, cur)
    }
    return ret
}