func largestNumber(nums []int) string {
    ret, n := strings.Builder{}, len(nums)
    nss := make([]string, n)
    for i, num := range nums {
        nss[i] = strconv.Itoa(num)
    }
    less := func (i, j int) bool {
        if nss[i] == nss[j] {
            return false
        }
        il, jl := len(nss[i]), len(nss[j])
        for p := 0; p == 0 || (p % il) != 0 || (p % jl) != 0; p++ {
            id, jd := nss[i][p % il], nss[j][p % jl]
            if id > jd {
                return true
            } else if id < jd {
                return false
            }
        }
        return false
    }
    sort.Slice(nss, less)
    for _, ns := range nss {
        if ns == "0" && ret.String() == "0" {
            break
        }
        ret.WriteString(ns)
    }
    return ret.String()
}