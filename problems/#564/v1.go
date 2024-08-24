func nearestPalindromic(n string) string {
    if isLessThan10(n) || is10m(n) {
        num, _ := strconv.Atoi(n)
        return strconv.Itoa(num - 1)
    }
    if is10mPlus1(n) {
        num, _ := strconv.Atoi(n)
        return strconv.Itoa(num - 2)
    }
    if isAll9(n) {
        num, _ := strconv.Atoi(n)
        return strconv.Itoa(num + 2)
    }
    nLen := len(n) 
    isLenEven := nLen % 2 == 0
    num, _ := strconv.Atoi(n)
    var root int
    if isLenEven {
        root, _ = strconv.Atoi(n[:nLen / 2])
    } else {
        root, _ = strconv.Atoi(n[:nLen / 2 + 1])
    }
    equalRootPalindrome := buildPalindromeFromRoot(strconv.Itoa(root), isLenEven)
    equalRootPalindromeNum, _ := strconv.Atoi(equalRootPalindrome)
    biggerRootPalindrome := buildPalindromeFromRoot(strconv.Itoa(root + 1), isLenEven)
    biggerRootPalindromeNum, _ := strconv.Atoi(biggerRootPalindrome)
    smallerRootPalindrome := buildPalindromeFromRoot(strconv.Itoa(root - 1), isLenEven)
    smallerRootPalindromeNum, _ := strconv.Atoi(smallerRootPalindrome)
    var ret, minDiff int
    if biggerRootPalindromeNum - num < num - smallerRootPalindromeNum {
        ret, minDiff = biggerRootPalindromeNum, biggerRootPalindromeNum - num
    } else {
        ret, minDiff = smallerRootPalindromeNum, num - smallerRootPalindromeNum
    }
    if equalRootPalindromeNum != num {
        diff := abs(equalRootPalindromeNum - num)
        if minDiff == diff {
            ret = min(ret, equalRootPalindromeNum)
        } else if minDiff > diff {
            ret = equalRootPalindromeNum
        }
    }
    return strconv.Itoa(ret)
}

func abs(num int) int {
    if num < 0 {
        return -num
    }
    return num
}

func isLessThan10(n string) bool {
    return len(n) == 1
}

func is10m(n string) bool {
    if n[0] != '1' {
        return false
    }
    nLen := len(n)
    for i := 1; i < nLen; i++ {
        if n[i] != '0' {
            return false
        }
    }
    return true
}

func is10mPlus1(n string) bool {
    if n[0] != '1' {
        return false
    }
    nLen := len(n)
    if n[nLen - 1] != '1' {
        return false
    }
    for i := 1; i < nLen - 1; i++ {
        if n[i] != '0' {
            return false
        }
    }
    return true
}

func isAll9(n string) bool {
    for _, c := range n {
        if c != '9' {
            return false
        }
    }
    return true
}

func buildPalindromeFromRoot(root string, isLenEven bool) string {
    rLen := len(root)
    fLen := 2 * rLen
    if !isLenEven {
        fLen--
    }
    chars := make([]byte, fLen)
    for l, r := 0, fLen - 1; l <= r; l, r = l + 1, r - 1 {
        chars[l], chars[r] = root[l], root[l]
    }
    return string(chars)
}