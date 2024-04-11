class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stk = []
        for d in num:
            while len(stk) > 0 and k > 0 and stk[-1] > d:
                stk.pop()
                k -= 1
            if len(stk) > 0 or d != '0':
                stk.append(d)
        if k > 0: 
            stk = stk[0:-k]
        return '0' if len(stk) == 0 else ''.join(stk)