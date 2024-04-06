class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        s = list(s)
        stk = []
        for i, c in enumerate(s):
            if c == '(':
                stk.append(i)
            elif c == ')':
                if len(stk) > 0:
                    stk.pop()
                else:
                    s[i] = ''
        while len(stk) > 0:
            s[stk.pop()] = ''
        return ''.join(s)