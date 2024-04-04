class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        n, sm, tm = len(s), {}, {}
        for i in range(n):
            if (t[i] in tm and tm[t[i]] != s[i]) or (s[i] in sm and sm[s[i]] != t[i]):
                return False
            sm[s[i]] = t[i]
            tm[t[i]] = s[i]
        return True