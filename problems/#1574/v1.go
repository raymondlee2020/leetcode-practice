func findLengthOfShortestSubarray(arr []int) int {
    n := len(arr)
    l, r := 0, n - 1
    for l + 1 < n && arr[l] <= arr[l + 1] {
        l++
    }
    if l == n - 1 {
        return 0
    }
    for r - 1 >= 0 && arr[r - 1] <= arr[r] {
        r--
    }
    ret, i, j := min(n - 1 - l, r), 0, r
    for i <= l && j < n {
        if arr[i] <= arr[j] {
            ret = min(ret, j - 1 - i)
            i++
        } else {
            j++
        }
    }
    return ret
}