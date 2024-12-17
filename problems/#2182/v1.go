func repeatLimitedString(s string, repeatLimit int) string {
    ret, cnt := make([]byte, 0), make([]int, 26)
    for _, c := range s {
        cnt[c - 'a']++
    }
    nxtAvaiChar := func(i int) int {
        for j := i - 1; j >= 0; j-- {
            if cnt[j] > 0 {
                return j
            }
        }
        return i
    }
    cur := nxtAvaiChar(26)
    nxt := nxtAvaiChar(cur)
    for !((cnt[cur] > 0 && cnt[nxt] == 0) || cur == nxt) {
        if cnt[cur] <= repeatLimit {
            for ; cnt[cur] > 0; cnt[cur]-- {
                ret = append(ret, byte(cur + 'a'))
            }
            cur, nxt = nxt, nxtAvaiChar(nxt)
        } else {
            for _ = range repeatLimit {
                ret = append(ret, byte(cur + 'a'))
            }
            ret = append(ret, byte(nxt + 'a'))
            cnt[cur], cnt[nxt] = cnt[cur] - repeatLimit, cnt[nxt] - 1
            if cnt[nxt] == 0 {
                nxt = nxtAvaiChar(nxt)
            }
        }
    }
    if cnt[cur] < repeatLimit {
        for ; cnt[cur] > 0; cnt[cur]-- {
            ret = append(ret, byte(cur + 'a'))
        }
    } else {
        for _ = range repeatLimit {
            ret = append(ret, byte(cur + 'a'))
        }
    }
    return string(ret)
}