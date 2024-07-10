func minOperations(logs []string) int {
	ret := 0
	for _, log := range logs {
		if log == "../" {
			ret = max(0, ret-1)
		} else if log != "./" {
			ret++
		}
	}
	return ret
}