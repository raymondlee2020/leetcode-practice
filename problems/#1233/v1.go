func removeSubfolders(folder []string) []string {
    ret, n := make([]string, 0), len(folder)
    sort.Strings(folder)
    ret = append(ret, folder[0])
    for i := 1; i < n; i++ {
        lf := ret[len(ret) - 1] + "/"
        if !strings.HasPrefix(folder[i], lf) {
            ret = append(ret, folder[i])
        }
    }
    return ret
}