class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        ret = 0
        for c in reversed(s):
            if c == ' ':
                if ret == 0:
                    continue
                break
            ret += 1
        return ret