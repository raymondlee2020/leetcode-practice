func maxChunksToSorted(arr []int) int {
    ret, n := 0, len(arr)
    for i, j, pre, cur := -1, 0, -1, arr[0]; j < n; j++ {
        cur = max(cur, arr[j])
        if j - i == cur - pre {
            ret++
            i, pre = j, cur
        }
    }
    return ret
}