class Solution:
    def makeGood(self, s: str) -> str:
        ret, n, bad_diff =  s[0], len(s), abs(ord('a') - ord('A'))
        for i in range(1, n):
            if len(ret) and abs(ord(s[i]) - ord(ret[-1])) == bad_diff:
                ret = ret[:-1]
            else:
                ret += s[i]
        return ret
            