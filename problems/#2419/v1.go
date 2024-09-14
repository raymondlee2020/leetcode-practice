func longestSubarray(nums []int) int {
    maxnum, cnt, prev, ret := 0, 0, 0, 0
    for _, num := range nums {
        if num > maxnum {
            maxnum, cnt, ret = num, 1, 1
        } else if num == maxnum {
            if num == prev {
                cnt++
                ret = max(ret, cnt)
            } else {
                cnt = 1
            }
        }
        prev = num
    }
    return ret
}