func getLucky(s string, k int) int {
    ret := 0
    for _, c := range s {
        cn := int(c - 'a' + 1)
        for cn > 0 {
            ret += cn % 10
            cn /= 10
        }
    }
    k--
    for ret > 9 && k > 0 {
        tmp := 0
        for ret > 0 {
            tmp += ret % 10
            ret /= 10
        }
        ret = tmp
        k--
    }
    return ret
}