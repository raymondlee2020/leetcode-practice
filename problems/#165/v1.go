func compareVersion(version1 string, version2 string) int {
	n1, n2 := len(version1), len(version2)
	for i1, i2, v1, v2 := 0, 0, 0, 0; i1 < n1 || i2 < n2; i1, i2 = i1+1, i2+1 {
		v1, i1 = nextVer(version1, i1)
		v2, i2 = nextVer(version2, i2)
		if v1 < v2 {
			return -1
		}
		if v1 > v2 {
			return 1
		}
	}
	return 0
}

func nextVer(ver string, l int) (res int, r int) {
	n := len(ver)
	if l > n {
		return 0, l
	}
	for r = l; r < n; r++ {
		if ver[r] == '.' {
			break
		}
	}
	res, _ = strconv.Atoi(ver[l:r])
	return
}