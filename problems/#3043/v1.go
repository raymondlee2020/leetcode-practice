func longestCommonPrefix(arr1 []int, arr2 []int) int {
    ret, m := 0, make(map[int]bool)
    for _, num := range arr1 {
        for num > 0 {
            m[num] = true
            num /= 10
        }
    }
    for _, num := range arr2 {
        d := digit(num)
        for num > 0 {
            if m[num] {
                ret = max(ret, d)
            }
            d--
            num /= 10
        }
    }
    return ret
}

func digit(num int) int {
    ret := 0
    for num > 0 {
        ret++
        num /= 10
    }
    return ret
}