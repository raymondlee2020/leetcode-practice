class Solution:
    def maxDepth(self, s: str) -> int:
        ret, curr = 0, 0
        for c in s:
            if c == '(':
                curr += 1
                ret = max(ret, curr)
            elif c == ')':
                curr -= 1
        return ret