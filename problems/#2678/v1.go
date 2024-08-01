func countSeniors(details []string) int {
	ret := 0
	for _, detail := range details {
		age, _ := strconv.ParseInt(detail[11:13], 10, 7)
		if age > 60 {
			ret++
		}
	}
	return ret
}