func fractionAddition(expression string) string {
    numerator, denominator, nums := 0, 1, make([]string, 0)
    prev := 0
    for i, c := range expression {
        if c != '-' && c != '+' || i == 0 {
            continue
        }
        nums = append(nums, expression[prev:i])
        prev = i
    }
    nums = append(nums, expression[prev:])
    for _, num := range nums {
        tmp := strings.Split(num, "/")
        n, _ := strconv.Atoi(tmp[0])
        d, _ := strconv.Atoi(tmp[1])
        numerator = numerator * d + n * denominator
        denominator *= d
    }
    gcdNum := gcd(numerator, denominator)
    return fmt.Sprintf("%d/%d", numerator / gcdNum, denominator / gcdNum)
}

func gcd(a, b int) int {
	if a < 0 {
		a *= -1
	}

	for a > 0 {
		a, b = b % a, a
	}
	return b
}