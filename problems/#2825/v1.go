func canMakeSubsequence(str1 string, str2 string) bool {
    n, i := len(str2), 0
    for _, c := range str1 {
        bc := byte(c)
        if str2[i] == bc || str2[i] == cyclicNextChar(bc) {
            i++
        }
        if i == n {
            return true
        }
    }
    return false
}

func cyclicNextChar(c byte) byte {
    return byte((c - 'a' + 1) % 26 + 'a')
}