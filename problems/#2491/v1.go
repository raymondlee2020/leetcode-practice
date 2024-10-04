func dividePlayers(skill []int) int64 {
    ret, l, r := int64(0), 0, len(skill) - 1
    sort.Ints(skill)
    total := skill[l] + skill[r]
    for ; l < r; l, r = l + 1, r - 1 {
        if skill[l] + skill[r] != total {
            return -1
        }
        ret += int64(skill[l] * skill[r])
    }
    return ret
}